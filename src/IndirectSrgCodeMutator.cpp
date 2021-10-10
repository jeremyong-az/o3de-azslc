/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 * 
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#include "IndirectSrgCodeMutator.h"

namespace AZ::ShaderCompiler
{
    IndirectSrgCodeMutator::IndirectSrgCodeMutator(IntermediateRepresentation* ir)
        : m_ir{ ir }
    {}

    const CodeMutation* IndirectSrgCodeMutator::GetMutation(ssize_t tokenId) const
    {
        return nullptr;
    }

    void IndirectSrgCodeMutator::enterAttributedSrgDefinition(azslParser::AttributedSrgDefinitionContext* ctx)
    {
        const std::vector<azslParser::AttributeSpecifierAnyContext*>& attributes = ctx->attributeSpecifierAny();
        for (azslParser::AttributeSpecifierAnyContext* attribute : attributes)
        {
            azslParser::AttributeSpecifierContext* specifier = attribute->attributeSpecifier();
            std::cout << specifier->attribute()->getText() << std::endl;
        }
    }
}