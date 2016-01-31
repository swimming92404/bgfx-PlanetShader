#include "skybox.h"


struct PosColorTexCoord0Vertex
{
	float m_x;
	float m_y;
	float m_z;
	float m_u;
	float m_v;

	static void init()
		{
			ms_decl
				.begin()
				.add(bgfx::Attrib::Position,  3, bgfx::AttribType::Float)
				.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
				.end();
		}

	static bgfx::VertexDecl ms_decl;
};



bgfx::VertexDecl PosColorTexCoord0Vertex::ms_decl;


static PosColorTexCoord0Vertex s_cubeVertices[8] =
{
	{-10.0f,  10.0f,  10.0f, 0, 0},
	{ 10.0f,  10.0f,  10.0f, 0x7fff, 0 },
	{-10.0f, -10.0f,  10.0f, 0, 0x7fff },
	{ 10.0f, -10.0f,  10.0f, 0x7fff, 0x7fff },
	{-10.0f,  10.0f, -10.0f, 0, 0 },
	{ 10.0f,  10.0f, -10.0f, 0x7fff, 0 },
	{-10.0f, -10.0f, -10.0f, 0, 0x7fff },
	{ 10.0f, -10.0f, -10.0f, 0x7fff, 0x7fff},
};

static const uint16_t s_cubeIndices[36] =
{
	2, 1, 0, // 0
	2, 3, 1,
	5, 6, 4, // 2
	7, 6, 5,
	4, 2, 0, // 4
	6, 2, 4,
	3, 5, 1, // 6
	3, 7, 5,
	1, 4, 0, // 8
	1, 5, 4,
	6, 3, 2, // 10
	7, 3, 6,
};

Skybox::~Skybox()
{
	bgfx::destroyIndexBuffer(m_ibh);
}

void Skybox::setupSkybox()
{
	PosColorTexCoord0Vertex::init();
	m_vbh = bgfx::createVertexBuffer(
		// Static data can be passed with bgfx::makeRef
		bgfx::makeRef(s_cubeVertices, sizeof(s_cubeVertices) )
		, PosColorTexCoord0Vertex::ms_decl
		);

	m_ibh = bgfx::createIndexBuffer(
		// Static data can be passed with bgfx::makeRef
		bgfx::makeRef(s_cubeIndices, sizeof(s_cubeIndices) )
		);

	//load a texture here
	m_texture.setStage(0);
	m_texture.loadTexture("mars_map.bmp",  0 | BGFX_TEXTURE_U_MIRROR
					  | BGFX_TEXTURE_V_MIRROR
					  | BGFX_TEXTURE_W_MIRROR);
}


void Skybox::renderSkybox(bgfx::ProgramHandle program)
{

	//render skybox code here
	bgfx::touch(0);
	float mtx[16];
	//bx::mtxScale(mtx, 10, 10, 10);
	//bgfx::setTransform(mtx);
	bgfx::setVertexBuffer(m_vbh);
	bgfx::setIndexBuffer(m_ibh);
	bgfx::setState(BGFX_STATE_DEFAULT);
	m_texture.setTexture();
	bgfx::submit(0, program);
}
