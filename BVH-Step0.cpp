#include <fmt/format.h>
#include <vector>
#include <chrono>
#include <memory>
#include <future>

#include <glm/glm.hpp>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

constexpr size_t N=64;
constexpr float SWIDTH = 512;
constexpr float SHEIGHT = 512;

struct Tri
{
	glm::vec3 v0, v1, v2;
	glm::vec3 centroid;
};

Tri tris[N];

struct Ray
{
	glm::vec3 O;
	glm::vec3 D;
	float t = 1e30f;
};

void intersectTri(const Tri &tri,Ray &ray)
{
    const glm::vec3 edge2 = tri.v2 - tri.v0;
    const glm::vec3 edge1 = tri.v1 - tri.v0;
    const glm::vec3 h = cross(ray.D, edge2);
    const float a = dot(edge1, h);
    if (a > -0.0001f && a < 0.0001f) return; // ray parallel to triangle
    const float f = 1 / a;
    const glm::vec3 s = ray.O - tri.v0;
    const float u = f * dot(s, h);
    if (u < 0 || u > 1) return;
    const glm::vec3 q = cross(s, edge1);
    const float v = f * dot(ray.D, q);
    if (v < 0 || u + v > 1) return;
    const float t = f * dot(edge2, q);
    if (t > 0.0001f) ray.t = std::min(ray.t, t);
}

int main()
{
    //Generate triangles
    for (int i = 0; i < N; i++)
    {
        glm::vec3 r0((rand()%100)/100.0f, (rand()%100)/100.0f, (rand()%100)/100.0f);
        glm::vec3 r1((rand()%100)/100.0f, (rand()%100)/100.0f, (rand()%100)/100.0f);
        glm::vec3 r2((rand()%100)/100.0f, (rand()%100)/100.0f, (rand()%100)/100.0f);
        tris[i].v0 = r0 * 9.0f - glm::vec3(5);
        tris[i].v1 = tris[i].v0 + r1;
        tris[i].v2 = tris[i].v0 + r2;
    }
	
    constexpr glm::vec3 CAMPOS = glm::vec3(0,0,25);
    constexpr glm::vec3 TopLeft = glm::vec3(-1, 1, 15);
    constexpr glm::vec3 TopRight = glm::vec3(1, 1, 15);
    constexpr glm::vec3 BottomLeft = glm::vec3(-1, -1, 15);


    constexpr size_t pixCount = static_cast<size_t>(SWIDTH)* static_cast<size_t>(SHEIGHT)*3;
    std::vector<unsigned char> pixels(pixCount);
    glm::vec3 triColor = glm::vec3(255*0.1,255*0.2,255*0.3);
    Ray ray;
    ray.O = CAMPOS;
    for (int y = 0;y<SHEIGHT;y++)
    {
        for (int x = 0; x < SWIDTH; x++)
        {
            auto pixelPos = TopLeft + (TopRight - TopLeft) * (x / SWIDTH) +
                ((BottomLeft - TopLeft) * (y / SHEIGHT));
            ray.O = CAMPOS;
            ray.D = glm::normalize(pixelPos-CAMPOS);
            ray.t = 1e30f;
            size_t pixelIndex = (y * static_cast<size_t>(SWIDTH) * 3) + static_cast<size_t>(x) * 3;
            for (int i = 0; i < N; i++)
            {
                intersectTri(tris[i], ray);
                if (ray.t < 1e30f)
                {
                    pixels.at(pixelIndex) = triColor.r;
                    pixels.at(pixelIndex+1) = triColor.g;
                    pixels.at(pixelIndex+2) = triColor.b;
                }
            }
        }
    }

    stbi_write_jpg("render.jpg", SWIDTH, SHEIGHT, 3, pixels.data(), 100);

	return EXIT_SUCCESS;
}


