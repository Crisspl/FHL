#ifndef FHL_GRAPHICS_MODEL_H
#define FHL_GRAPHICS_MODEL_H

#include <FHL/Graphics/Vao.h>
#include <FHL/Graphics/Transformable3D.h>
#include <FHL/Graphics/Litable.h>
#include <FHL/Graphics/UsingShader.h>
#include <FHL/Graphics/ModelData.h>
#include <FHL/Graphics/Color.h>
#include <FHL/Utility/OrientedCube.h>

namespace fhl
{
	class Renderer;

	class FHL_API Model :
		public Transformable3D,
		public Litable,
		public UsingShader
	{
		friend class Renderer;

		enum AttrLoc : GLuint
		{
			Position = 0,
			Normal,
			TexCoord
		};

	public:
		explicit Model(ModelData & _data);
		Model(const Model &) = delete;
		Model & operator=(const Model &) = delete;

		void setModelData(ModelData & _data);
		void setUseColorOnly(bool _val) { m_useColorOnly = _val; } // render textures or only single color
		void setColor(const Color & _color) { m_color = _color; }

		Vec3f getSize() const { return m_modelData->getSize(); }
		const std::vector<detail::Vao> & getVaos() const { return m_vaos; }
		const ModelData * getModelData() const { return m_modelData; }
		bool getUseColorOnly() const { return m_useColorOnly; }
		const Color & getColor() const { return m_color; }

		Cube getAABB() const;
		OrientedCube getOBB() const;

		static constexpr const char * simpleShaderName() { return s_simpleShaderName; }
		static constexpr const char * lightShaderName() { return s_lightShaderName; }

	private:
		void setUp();

	private:
		ModelData * m_modelData;
		std::vector<detail::Vao> m_vaos;
		Color m_color;
		bool m_useColorOnly;

		constexpr static const char * s_simpleShaderName = "_FHL_modelSimpleShader";
		constexpr static const char * s_lightShaderName = "_FHL_modelLightShader";
	};

}

#endif
