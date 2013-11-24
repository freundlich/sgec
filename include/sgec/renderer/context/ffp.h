#ifndef SGEC_RENDERER_CONTEXT_FFP_H_INCLUDED
#define SGEC_RENDERER_CONTEXT_FFP_H_INCLUDED

#include <sgec/result.h>
#include <sgec/symbol.hpp>
#include <sgec/detail/footer.h>
#include <sgec/detail/header.h>
#include <sgec/renderer/context/ffp_fwd.h>


SGEC_DETAIL_HEADER

SGEC_SYMBOL
enum sgec_result
sgec_renderer_context_ffp_clear(
	struct sgec_renderer_context_ffp *
);

SGEC_SYMBOL
enum sgec_result
sgec_renderer_context_ffp_destroy(
	struct sgec_renderer_context_ffp *
);

SGEC_DETAIL_FOOTER

#endif
