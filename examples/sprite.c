#include <sgec/image/color/make_rgba.h>
#include <sgec/input/key/code.h>
#include <sgec/input/key/state.h>
#include <sgec/renderer/context/ffp.h>
#include <sgec/renderer/device/ffp.h>
#include <sgec/renderer/texture/create_planar_from_path.h>
#include <sgec/renderer/texture/planar.h>
#include <sgec/sprite/draw.h>
#include <sgec/sprite/object.h>
#include <sgec/systems/cursor_option.h>
#include <sgec/systems/instance.h>
#include <sgec/texture/part.h>
#include <sgec/texture/part_raw.h>
#include <sgec/window/event.h>
#include <sgec/window/event_result.h>
#include <sgec/window/event_type.h>
#include <sgec/window/free_event.h>
#include <sgec/window/system.h>
#include <fcppt/config/external_begin.h>
#include <stdlib.h>
#include <fcppt/config/external_end.h>


int
main()
{
	struct sgec_systems_instance *instance =
		sgec_systems_instance_create(
			"sgec sprite test",
			0u,
			0u,
			sgec_systems_cursor_option_normal
		);

	if(
		instance
		==
		NULL
	)
		return
			EXIT_FAILURE;

	struct sgec_renderer_device_ffp *device =
		sgec_systems_instance_renderer(
			instance
		);

	struct sgec_window_system *window_system =
		sgec_systems_instance_window_system(
			instance
		);

	int exit_code =
		EXIT_SUCCESS;

	struct sgec_renderer_texture_planar *texture =
		sgec_renderer_texture_create_planar_from_path(
			device,
			sgec_systems_instance_image2d_system(
				instance
			),
			// TODO: Add a proper path here
			"media/car.png"
		);
	if(
		texture
		==
		NULL
	)
	{
		exit_code =
			EXIT_FAILURE;

		goto cleanup_instance;
	}

	struct sgec_texture_part *texture_part =
		sgec_texture_part_raw(
			texture
		);

	if(
		texture_part
		==
		NULL
	)
	{
		exit_code =
			EXIT_FAILURE;

		goto cleanup_texture;
	}

	struct sgec_sprite_object my_sprites[] = {
		{
			texture_part,
			150,
			150,
			200,
			200,
			0.f,
			sgec_image_color_make_rgba(
				255u,
				0u,
				0u,
				255u
			)
		},
		{
			texture_part,
			100,
			100,
			200,
			200,
			1.f,
			sgec_image_color_make_rgba(
				255u,
				255u,
				255u,
				255u
			)
		}
	};

	struct sgec_window_event next_event;

	while(
		sgec_window_system_next_event(
			window_system,
			&next_event
		)
		==
		sgec_window_event_result_running
	)
	{
		if(
			next_event.type
			==
			sgec_window_event_type_render
		)
		{
			struct sgec_renderer_context_ffp *context =
				sgec_renderer_device_ffp_begin_rendering(
					device
				);

			if(
				context
				!=
				NULL
			)
			{
				// May fail, ignore
				sgec_renderer_context_ffp_clear(
					context,
					sgec_image_color_make_rgba(
						0,
						0,
						0,
						0
					)
				);

				sgec_sprite_draw(
					device,
					context,
					0u,
					0u,
					my_sprites,
					sizeof(
						my_sprites
					)
					/
					sizeof(
						struct sgec_sprite_object
					)
				);

				sgec_renderer_device_ffp_end_rendering(
					device,
					context
				);

				sgec_renderer_context_ffp_destroy(
					context
				);
			}
		}
		else if(
			next_event.type
			==
			sgec_window_event_type_keyboard_key
		)
		{
			struct sgec_input_keyboard_key_event const key_event =
				next_event.keyboard_key;

			if(
				key_event.key_state
				==
				sgec_input_key_state_pressed
				&&
				key_event.key_code
				==
				sgec_input_key_code_escape
			)
				sgec_window_system_quit(
					window_system,
					EXIT_SUCCESS
				);
		}

		sgec_window_free_event(
			&next_event
		);
	}

	exit_code =
		sgec_window_system_exit_code(
			window_system
		);

	sgec_texture_part_destroy(
		texture_part
	);

cleanup_texture:
	sgec_renderer_texture_planar_destroy(
		texture
	);

cleanup_instance:
	sgec_systems_instance_destroy(
		instance
	);

	return
		exit_code;
}
