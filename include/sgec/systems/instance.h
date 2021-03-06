#ifndef SGEC_SYSTEMS_INSTANCE_H_INCLUDED
#define SGEC_SYSTEMS_INSTANCE_H_INCLUDED

#include <sgec/result.h>
#include <sgec/detail/symbol.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/audio/loader_fwd.h>
#include <sgec/audio/player_fwd.h>
#include <sgec/font/system_fwd.h>
#include <sgec/image2d/system_fwd.h>
#include <sgec/renderer/device/ffp_fwd.h>
#include <sgec/systems/cursor_option.h>
#include <sgec/systems/instance_fwd.h>
#include <sgec/window/unit.h>
#include <sgec/window/system_fwd.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
struct sgec_systems_instance *
sgec_systems_instance_create(
	char const *window_name,
	sgec_window_unit width, /* 0 for arbitrary width */
	sgec_window_unit height, /* 0 for arbitrary height */
	enum sgec_systems_cursor_option
);

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_systems_instance_destroy(
	struct sgec_systems_instance *
);

SGEC_DETAIL_SYMBOL
struct sgec_renderer_device_ffp *
sgec_systems_instance_renderer(
	struct sgec_systems_instance *
);

SGEC_DETAIL_SYMBOL
struct sgec_window_system *
sgec_systems_instance_window_system(
	struct sgec_systems_instance *
);

SGEC_DETAIL_SYMBOL
struct sgec_image2d_system *
sgec_systems_instance_image2d_system(
	struct sgec_systems_instance *
);

SGEC_DETAIL_SYMBOL
struct sgec_font_system *
sgec_systems_instance_font_system(
	struct sgec_systems_instance *
);

SGEC_DETAIL_SYMBOL
struct sgec_audio_loader *
sgec_systems_instance_audio_loader(
	struct sgec_systems_instance *
);

SGEC_DETAIL_SYMBOL
struct sgec_audio_player *
sgec_systems_instance_audio_player(
	struct sgec_systems_instance *
);

SGEC_DETAIL_FOOTER

#endif
