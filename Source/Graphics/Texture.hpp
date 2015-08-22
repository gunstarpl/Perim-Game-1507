#pragma once

#include "Precompiled.hpp"

//
// Texture
//

namespace Graphics
{
    // Texture class.
    class Texture
    {
    public:
        // Texture view structure.
        struct View
        {
            View(const Texture& texture, const glm::vec4& rectangle);

            float GetWidth() const;
            float GetHeight() const;

            const glm::vec4 rectangle;
            const Texture& texture;
        };

    public:
        Texture();
        ~Texture();

        // Restores instance to it's original state.
        void Cleanup();

        // Loads the texture from a file.
        bool Load(std::string filename);

        // Initializes the texture instance.
        bool Initialize(int width, int height, GLenum format, const void* data);

        // Updates the texture data.
        void Update(const void* data);

        // Gets the texture view.
        View GetView(const glm::vec4& rectangle);

        // Gets the texture handle.
        GLuint GetHandle() const
        {
            return m_handle;
        }

        // Gets the texture width.
        int GetWidth() const
        {
            return m_width;
        }

        // Gets the texture height.
        int GetHeight() const
        {
            return m_height;
        }

        // Checks if instance is valid.
        bool IsValid() const
        {
            return m_initialized;
        }

    private:
        // Texture handle.
        GLuint m_handle;

        // Texture parameters.
        int m_width;
        int m_height;
        GLenum m_format;

        // Initialization state.
        bool m_initialized;
    };
}
