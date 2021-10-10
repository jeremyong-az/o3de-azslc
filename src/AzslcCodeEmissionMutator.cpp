/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 * 
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include "AzslcCodeEmissionMutator.h"

namespace AZ::ShaderCompiler
{
    const CodeMutation* CombinedCodeMutator::GetMutation(ssize_t tokenIndex) const
    {
        for (const ICodeEmissionMutator* mutator : m_mutators)
        {
            if (const CodeMutation* mutation = mutator->GetMutation(tokenIndex))
            {
                return mutation;
            }
        }
        return nullptr;
    }
}