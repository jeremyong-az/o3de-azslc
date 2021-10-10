/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 * 
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include <vector>

#include "AzslcUtils.h"

namespace AZ::ShaderCompiler
{
    //! In this struct we store text mutations
    //! for code emissions.
    struct CodeMutation
    {
        //! If present, this string will be emitted first.
        std::optional<std::string> m_prepend;

        //! If present, the TokenIndex should not be looked up for its proper qualified symbol.
        //! instead, it should be replaced with this text when it's time to emit.
        std::optional<std::string> m_replace;

        //! After the token text was emitted, this text will be emitted if present.
        std::optional<std::string> m_append;
    };

    //! This is a companion interface for the CodeEmitter. The code emitter may hold a reference
    //! to one of these.
    //! During code emission the CodeEmitter will call GetMutation() for some tokens
    //! and change the output accordingly.
    class ICodeEmissionMutator
    {
    public:
        virtual ~ICodeEmissionMutator() = default;

        //! Returns nullptr if there's no mutation for the given tokenIndex.
        //! tokenIndex refers to the exact same integral as returned by antlr4::Token::getTokenIndex().
        virtual const CodeMutation* GetMutation(ssize_t tokenIndex) const = 0;
    };

    //! Helper mutator class that layers the effects of multiple mutators behind a single object.
    //! Each mutator added is processed in order and given an opportunity to produce a mutation. The
    //! first mutator that produces a non-nullptr mutation short-circuits the loop.
    class CombinedCodeMutator : public ICodeEmissionMutator
    {
    public:
        ~CombinedCodeMutator() override = default;

        //! Add a mutator to the chain that will process before other mutators added afterwards
        void Add(ICodeEmissionMutator* mutator)
        {
            m_mutators.push_back(mutator);
        }

        //! ICodeEmissionMutator override
        const CodeMutation* GetMutation(ssize_t tokenIndex) const override;

    private:
        std::vector<ICodeEmissionMutator*> m_mutators;
    };
} // namespace AZ::ShaderCompiler
