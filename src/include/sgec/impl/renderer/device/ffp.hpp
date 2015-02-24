#ifndef SGEC_IMPL_RENDERER_DEVICE_FFP_HPP_INCLUDED
#define SGEC_IMPL_RENDERER_DEVICE_FFP_HPP_INCLUDED

#include <sgec/renderer/context/ffp_fwd.h>
#include <sgec/renderer/device/ffp_fwd.h>
#include <sgec/renderer/target/onscreen_fwd.h>
#include <sge/renderer/device/ffp_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


struct sgec_renderer_device_ffp
{
	FCPPT_NONCOPYABLE(
		sgec_renderer_device_ffp
	);
public:
	explicit
	sgec_renderer_device_ffp(
		sge::renderer::device::ffp &
	);

	~sgec_renderer_device_ffp();

	sgec_renderer_context_ffp *
	begin_rendering();

	void
	end_rendering(
		sgec_renderer_context_ffp *
	);

	sgec_renderer_target_onscreen &
	onscreen_target() const;

	sge::renderer::device::ffp &
	get();
private:
	sge::renderer::device::ffp &device_;

	typedef
	std::unique_ptr<
		sgec_renderer_target_onscreen
	>
	scoped_target_onscreen_ptr;

	scoped_target_onscreen_ptr const onscreen_target_;
};

#endif
