#ifndef SGEC_TEXTURE_PART_H_INCLUDED
#define SGEC_TEXTURE_PART_H_INCLUDED

#include <sgec/result.h>
#include <sgec/detail/symbol.h>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/renderer/texture/size.h>
#include <sgec/texture/part_fwd.h>


SGEC_DETAIL_HEADER

SGEC_DETAIL_SYMBOL
sgec_renderer_texture_size
sgec_texture_part_width(
	struct sgec_texture_part const *
);

SGEC_DETAIL_SYMBOL
sgec_renderer_texture_size
sgec_texture_part_height(
	struct sgec_texture_part const *
);

SGEC_DETAIL_SYMBOL
enum sgec_result
sgec_texture_part_destroy(
	struct sgec_texture_part *
);

SGEC_DETAIL_FOOTER

#endif
