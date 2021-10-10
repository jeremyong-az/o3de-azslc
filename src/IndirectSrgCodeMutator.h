/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 * 
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include "GenericUtils.h"
#include "AzslcUtils.h"
#include "AzslcCodeEmissionMutator.h"
#include "AzslcIntermediateRepresentation.h"

namespace AZ::ShaderCompiler
{
    class IndirectSrgCodeMutator
        : public azslParserBaseListener
        , public ICodeEmissionMutator
    {
    public:
        explicit IndirectSrgCodeMutator(IntermediateRepresentation* ir);
        ~IndirectSrgCodeMutator() override = default;

        // ICodeEmissionMutator interface
        const CodeMutation* GetMutation(ssize_t tokenId) const override;

    private:
        // azslParserBaseListener overrides
        void enterAttributedSrgDefinition(azslParser::AttributedSrgDefinitionContext* ctx) override;

        IntermediateRepresentation* m_ir;
    };
}