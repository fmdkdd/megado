#pragma once

#include <GLFW/glfw3.h>
#include <stdbool.h>

#include "snapshot.h"
#include "vdp.h"
#include "metric.h"

struct SnapshotMetadata;

typedef struct Renderer
{
    Genesis* genesis;

    GLFWwindow* window;

    struct SnapshotMetadata* snapshots[SNAPSHOT_SLOTS];

    float last_time;
    float metrics_refresh_counter;
    float instructions_this_second;
    Metric* tpf; // time per frame
    Metric* ipf; // instructions per frame
    Metric* ips; // instructions per second

    enum Planes selected_plane;
    uint8_t* plane_buffer;
    uint8_t* sprites_buffer;

    uint32_t rom_target_address;
    uint32_t ram_target_address;
    uint32_t vram_target_address;

    // Graphics resources for rendering the Genesis' output
    GLuint game_shader;
    GLuint game_texture;
    GLuint game_vertex_array_object, game_vertex_buffer_object;
    GLint game_shader_projection_loc;

    // Graphics resources for the user interface
    GLuint ui_shader;
    GLuint ui_patterns_texture, ui_magnified_pattern_texture, ui_planes_texture, ui_sprites_texture;
    GLuint ui_vertex_array_object, ui_vertex_buffer_object, ui_element_buffer_object;
    GLint ui_shader_texture_loc, ui_shader_projection_loc;
} Renderer;

Renderer* renderer_make(Genesis*);
void renderer_free(Renderer*);

void renderer_render(Renderer*);
