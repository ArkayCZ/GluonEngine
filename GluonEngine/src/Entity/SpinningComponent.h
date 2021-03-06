﻿#pragma once

#include "EntityComponent.h"
#include "ComponentIds.h"
#include "Entity.h"

namespace ge { namespace components
{

	class SpinningComponent : public ge::components::EntityComponent
	{
	public:

		explicit SpinningComponent(const std::string& axes)
			: EntityComponent(Components::SPINNING)
		{
			m_Axes = axes;
		}


		~SpinningComponent() override;
		void OnInit(ge::InitBundle* bundle) override;
		void OnUpdate(ge::UpdateBundle* bundle) override;
		void OnRender(ge::RenderBundle* bundle) override;
		void OnDestroy() override;

	private:
		std::string m_Axes;
	};
}}

