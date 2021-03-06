#ifndef FHL_GRAPHICS_MESH_H
#define FHL_GRAPHICS_MESH_H

#include <string>
#include <vector>
#include <tuple>

#include <FHL/GL/OpenGL.h>
#include <FHL/Graphics/Buffer.h>
#include <FHL/Maths/vectors.h>


namespace fhl
{
	 class Model;
	 class ModelData;
	 class Texture;

namespace detail
{

	class FHL_API Mesh
	{
		using tuple3pair_t = std::tuple<std::pair<float, float>, std::pair<float, float>, std::pair<float, float>>;
		friend class fhl::Model;
		friend class fhl::ModelData;

		struct Vertex
		{
			Vec3f position;
			Vec3f normal;
			Vec2f texCoords;
		};

		struct TexturesPair
		{
			Texture * diffuse, * specular;
		};

	public:
		Mesh(const std::vector<Mesh::Vertex> & _vertices, const std::vector<GLuint> & _indices, TexturesPair _textures);

		Texture * getDiffuseTexture() const { return textures.diffuse; }
		Texture * getSpecularTexture() const { return textures.specular; }
		std::size_t getIndicesCount() const { return indicesCount; }

	private:
		void setUp(const std::vector<Mesh::Vertex> & _vertices, const std::vector<GLuint> & _indices);

		TexturesPair textures;
		std::size_t indicesCount;
		tuple3pair_t minMaxVerts;
		Buffer vbo, ebo;
	};

}}

#endif
