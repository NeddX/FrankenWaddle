#ifndef FRANKLIST_IMPL_H
#define FRANKLIST_IMPL_H

#include "FrankList.h"

namespace vhuk {
    template <typename T>
    FrankList<T>::base_iterator::base_iterator(Node* ptr) : m_Ptr(ptr)
    {
    }

    template <typename T>
    FrankList<T>::base_iterator::~base_iterator()
    {
    }

    template <typename T>
    bool FrankList<T>::base_iterator::operator==(const base_iterator& other) const
    {
        return m_Ptr == other.m_Ptr;
    }

    template <typename T>
    bool FrankList<T>::base_iterator::operator!=(const base_iterator& other) const
    {
        return !this->operator==(other);
    }

    template <typename T>
    FrankList<T>::const_iterator::const_iterator(const base_iterator& it) : base_iterator(it)
    {
    }

    template <typename T>
    FrankList<T>::const_iterator::const_iterator(base_iterator&& it) : base_iterator(std::move(it))
    {
    }

    template <typename T>
    FrankList<T>::const_iterator::const_iterator(Node* ptr) : base_iterator(ptr)
    {
    }

    template <typename T>
    const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator=(const base_iterator& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator=(base_iterator&& other)
    {
        if (this == &other)
            return *this;

        std::swap(base_iterator::m_Ptr, other.m_Ptr);
        return *this;
    }

    template <typename T>
    typename FrankList<T>::const_reference FrankList<T>::const_iterator::operator*() const
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    typename FrankList<T>::const_pointer FrankList<T>::const_iterator::operator->() const
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator++()
    {
        base_iterator::m_Ptr = base_iterator::m_Ptr->next;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_iterator FrankList<T>::const_iterator::operator++(value_type)
    {
        const auto cpy = *this;
        ++(*this);
        return cpy;
    }

    template <typename T>
    const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator--()
    {
        base_iterator::m_Ptr = base_iterator::m_Ptr->prev;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_iterator FrankList<T>::const_iterator::operator--(value_type)
    {
        const auto cpy = *this;
        --(*this);
        return cpy;
    }

    template <typename T>
    FrankList<T>::iterator::iterator(const base_iterator& other) : const_iterator(other)
    {
    }

    template <typename T>
    FrankList<T>::iterator::iterator(base_iterator&& other) : const_iterator(std::move(other))
    {
    }

    template <typename T>
    FrankList<T>::iterator::iterator(Node* ptr) : const_iterator(ptr)
    {
    }

    template <typename T>
    typename FrankList<T>::reference FrankList<T>::iterator::operator*()
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    typename FrankList<T>::pointer FrankList<T>::iterator::operator->()
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    const typename FrankList<T>::iterator& FrankList<T>::iterator::operator=(const base_iterator& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::iterator& FrankList<T>::iterator::operator=(base_iterator&& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        other.m_Ptr          = nullptr;
        return *this;
    }

    template <typename T>
    FrankList<T>::const_reverse_iterator::const_reverse_iterator(const base_iterator& other) : base_iterator(other)
    {
    }

    template <typename T>
    FrankList<T>::const_reverse_iterator::const_reverse_iterator(base_iterator&& other)
        : base_iterator(std::move(other))
    {
    }

    template <typename T>
    FrankList<T>::const_reverse_iterator::const_reverse_iterator(Node* ptr) : base_iterator(ptr)
    {
    }

    template <typename T>
    const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator=(
        const base_iterator& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator=(
        base_iterator&& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        other.m_Ptr          = nullptr;
        return *this;
    }

    template <typename T>
    typename FrankList<T>::const_reference FrankList<T>::const_reverse_iterator::operator*() const
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    typename FrankList<T>::const_pointer FrankList<T>::const_reverse_iterator::operator->() const
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator++()
    {
        base_iterator::m_Ptr = base_iterator::m_Ptr->prev;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator++(value_type)
    {
        const auto cpy = *this;
        ++(*this);
        return cpy;
    }

    template <typename T>
    const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator--()
    {
        base_iterator::m_Ptr = base_iterator::m_Ptr->next;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator--(value_type)
    {
        const auto cpy = *this;
        --(*this);
        return cpy;
    }

    template <typename T>
    FrankList<T>::reverse_iterator::reverse_iterator(const base_iterator& other) : const_reverse_iterator(other)
    {
    }

    template <typename T>
    FrankList<T>::reverse_iterator::reverse_iterator(base_iterator&& other) : const_reverse_iterator(std::move(other))
    {
    }

    template <typename T>
    FrankList<T>::reverse_iterator::reverse_iterator(Node* ptr) : const_reverse_iterator(ptr)
    {
    }

    template <typename T>
    const typename FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator=(const base_iterator& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator=(base_iterator&& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        other.m_Ptr          = nullptr;
        return *this;
    }

    template <typename T>
    typename FrankList<T>::reference FrankList<T>::reverse_iterator::operator*()
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    typename FrankList<T>::pointer FrankList<T>::reverse_iterator::operator->()
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    FrankList<T>::const_asc_iterator::const_asc_iterator(const base_iterator& other) : base_iterator(other)
    {
    }

    template <typename T>
    FrankList<T>::const_asc_iterator::const_asc_iterator(base_iterator&& other) : base_iterator(std::move(other))
    {
    }

    template <typename T>
    FrankList<T>::const_asc_iterator::const_asc_iterator(Node* ptr) : base_iterator(ptr)
    {
    }

    template <typename T>
    const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator=(
        const base_iterator& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator=(base_iterator&& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        other.m_Ptr          = nullptr;
        return *this;
    }

    template <typename T>
    typename FrankList<T>::const_reference FrankList<T>::const_asc_iterator::operator*() const
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    typename FrankList<T>::const_pointer FrankList<T>::const_asc_iterator::operator->() const
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator++()
    {
        base_iterator::m_Ptr = base_iterator::m_Ptr->asc;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator++(value_type)
    {
        const auto cpy = *this;
        ++(*this);
        return cpy;
    }

    template <typename T>
    const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator--()
    {
        base_iterator::m_Ptr = base_iterator::m_Ptr->desc;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator--(value_type)
    {
        const auto cpy = *this;
        --(*this);
        return cpy;
    }

    template <typename T>
    FrankList<T>::asc_iterator::asc_iterator(const base_iterator& other) : const_asc_iterator(other)
    {
    }

    template <typename T>
    FrankList<T>::asc_iterator::asc_iterator(base_iterator&& other) : const_asc_iterator(std::move(other))
    {
    }

    template <typename T>
    FrankList<T>::asc_iterator::asc_iterator(Node* ptr) : const_asc_iterator(ptr)
    {
    }

    template <typename T>
    const typename FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator=(const base_iterator& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator=(base_iterator&& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        other.m_Ptr          = nullptr;
        return *this;
    }

    template <typename T>
    typename FrankList<T>::reference FrankList<T>::asc_iterator::operator*()
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    typename FrankList<T>::pointer FrankList<T>::asc_iterator::operator->()
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    FrankList<T>::const_desc_iterator::const_desc_iterator(const base_iterator& other) : base_iterator(other)
    {
    }

    template <typename T>
    FrankList<T>::const_desc_iterator::const_desc_iterator(base_iterator&& other) : base_iterator(std::move(other))
    {
    }

    template <typename T>
    FrankList<T>::const_desc_iterator::const_desc_iterator(Node* ptr) : base_iterator(ptr)
    {
    }

    template <typename T>
    const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator=(
        const base_iterator& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator=(
        base_iterator&& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        other.m_Ptr          = nullptr;
        return *this;
    }

    template <typename T>
    typename FrankList<T>::const_reference FrankList<T>::const_desc_iterator::operator*() const
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    typename FrankList<T>::const_pointer FrankList<T>::const_desc_iterator::operator->() const
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator++()
    {
        base_iterator::m_Ptr = base_iterator::m_Ptr->desc;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator++(value_type)
    {
        const auto cpy = *this;
        ++(*this);
        return cpy;
    }

    template <typename T>
    const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator--()
    {
        base_iterator::m_Ptr = base_iterator::m_Ptr->asc;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator--(value_type)
    {
        const auto cpy = *this;
        --(*this);
        return cpy;
    }

    template <typename T>
    FrankList<T>::desc_iterator::desc_iterator(const base_iterator& other) : const_desc_iterator(other)
    {
    }

    template <typename T>
    FrankList<T>::desc_iterator::desc_iterator(base_iterator&& other) : const_desc_iterator(std::move(other))
    {
    }

    template <typename T>
    FrankList<T>::desc_iterator::desc_iterator(Node* ptr) : const_desc_iterator(ptr)
    {
    }

    template <typename T>
    const typename FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator=(const base_iterator& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator=(base_iterator&& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        other.m_Ptr          = nullptr;
        return *this;
    }

    template <typename T>
    typename FrankList<T>::reference FrankList<T>::desc_iterator::operator*()
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    typename FrankList<T>::pointer FrankList<T>::desc_iterator::operator->()
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    FrankList<T>::const_multi_iterator::const_multi_iterator(const base_iterator& other) : base_iterator(other)
    {
    }

    template <typename T>
    FrankList<T>::const_multi_iterator::const_multi_iterator(base_iterator&& other) : base_iterator(std::move(other))
    {
    }

    template <typename T>
    FrankList<T>::const_multi_iterator::const_multi_iterator(Node* ptr) : base_iterator(ptr)
    {
    }

    template <typename T>
    const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator=(
        const base_iterator& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator=(
        base_iterator&& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        other.m_Ptr          = nullptr;
        return *this;
    }

    template <typename T>
    typename FrankList<T>::const_reference FrankList<T>::const_multi_iterator::operator*() const
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    typename FrankList<T>::const_pointer FrankList<T>::const_multi_iterator::operator->() const
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator++()
    {
        base_iterator::m_Ptr = (mode) ? base_iterator::m_Ptr->next : base_iterator::m_Ptr->asc;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_multi_iterator FrankList<T>::const_multi_iterator::operator++(value_type)
    {
        const auto cpy = *this;
        ++(*this);
        return cpy;
    }

    template <typename T>
    const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator--()
    {
        base_iterator::m_Ptr = (mode) ? base_iterator::m_Ptr->prev : base_iterator::m_Ptr->desc;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_multi_iterator FrankList<T>::const_multi_iterator::operator--(value_type)
    {
        const auto cpy = *this;
        --(*this);
        return cpy;
    }

    template <typename T>
    FrankList<T>::multi_iterator::multi_iterator(const base_iterator& other) : const_desc_iterator(other)
    {
    }

    template <typename T>
    FrankList<T>::multi_iterator::multi_iterator(base_iterator&& other) : const_desc_iterator(std::move(other))
    {
    }

    template <typename T>
    FrankList<T>::multi_iterator::multi_iterator(Node* ptr) : const_desc_iterator(ptr)
    {
    }

    template <typename T>
    const typename FrankList<T>::multi_iterator& FrankList<T>::multi_iterator::operator=(const base_iterator& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::multi_iterator& FrankList<T>::multi_iterator::operator=(base_iterator&& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        other.m_Ptr          = nullptr;
        return *this;
    }

    template <typename T>
    typename FrankList<T>::reference FrankList<T>::multi_iterator::operator*()
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    typename FrankList<T>::pointer FrankList<T>::multi_iterator::operator->()
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    void FrankList<T>::const_multi_iterator::chmod()
    {
        mode = !mode;
    }

    template <typename T>
    FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(const base_iterator& other)
        : base_iterator(other)
    {
    }

    template <typename T>
    FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(base_iterator&& other)
        : base_iterator(std::move(other))
    {
    }

    template <typename T>
    FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(Node* ptr) : base_iterator(ptr)
    {
    }

    template <typename T>
    const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator=(
        const base_iterator& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator=(
        base_iterator&& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        other.m_Ptr          = nullptr;
        return *this;
    }

    template <typename T>
    typename FrankList<T>::const_reference FrankList<T>::const_multi_reverse_iterator::operator*() const
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    typename FrankList<T>::const_pointer FrankList<T>::const_multi_reverse_iterator::operator->() const
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator++()
    {
        base_iterator::m_Ptr = (mode) ? base_iterator::m_Ptr->prev : base_iterator::m_Ptr->desc;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::const_multi_reverse_iterator::operator++(
        value_type)
    {
        const auto cpy = *this;
        ++(*this);
        return cpy;
    }

    template <typename T>
    const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator--()
    {
        base_iterator::m_Ptr = (mode) ? base_iterator::m_Ptr->next : base_iterator::m_Ptr->asc;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::const_multi_reverse_iterator::operator--(
        value_type)
    {
        const auto cpy = *this;
        --(*this);
        return cpy;
    }

    template <typename T>
    FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(const base_iterator& other)
        : const_desc_iterator(other)
    {
    }

    template <typename T>
    FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(base_iterator&& other)
        : const_desc_iterator(std::move(other))
    {
    }

    template <typename T>
    FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(Node* ptr) : const_desc_iterator(ptr)
    {
    }

    template <typename T>
    const typename FrankList<T>::multi_reverse_iterator& FrankList<T>::multi_reverse_iterator::operator=(
        const base_iterator& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        return *this;
    }

    template <typename T>
    const typename FrankList<T>::multi_reverse_iterator& FrankList<T>::multi_reverse_iterator::operator=(
        base_iterator&& other)
    {
        if (this == &other)
            return *this;

        base_iterator::m_Ptr = other.m_Ptr;
        other.m_Ptr          = nullptr;
        return *this;
    }

    template <typename T>
    typename FrankList<T>::reference FrankList<T>::multi_reverse_iterator::operator*()
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    typename FrankList<T>::pointer FrankList<T>::multi_reverse_iterator::operator->()
    {
        return base_iterator::m_Ptr->val;
    }

    template <typename T>
    void FrankList<T>::const_multi_reverse_iterator::chmod()
    {
        mode = !mode;
    }

    template <typename T>
    FrankList<T>::Node::Node() : val(T()), next(nullptr), prev(nullptr), asc(nullptr), desc(nullptr)
    {
    }

    template <typename T>
    FrankList<T>::Node::Node(T val) : val(std::move(val)), next(nullptr), prev(nullptr), asc(nullptr), desc(nullptr)
    {
    }

    template <typename T>
    FrankList<T>::FrankList() : m_Head(nullptr), m_Tail(nullptr), m_AHead(nullptr), m_ATail(nullptr)
    {
    }

    template <typename T>
    FrankList<T>::FrankList(size_type size) : FrankList()
    {
        resize(size);
    }

    template <typename T>
    FrankList<T>::FrankList(size_type size, const_reference init) : FrankList()
    {
        for (auto i = 0; i < size; ++i)
            push_back(init);
    }

    template <typename T>
    FrankList<T>::FrankList(const FrankList<T>& other) : FrankList()
    {
        for (const auto& e : other)
            push_back(e);
    }

    template <typename T>
    FrankList<T>::FrankList(FrankList<T>&& other) : FrankList()
    {
        swap(other);
    }

    template <typename T>
    FrankList<T>::FrankList(const std::initializer_list<value_type>& list) : FrankList<T>()
    {
        insert(end(), list.begin(), list.end());
    }

    template <typename T>
    template <typename input_iterator, typename>
    FrankList<T>::FrankList(input_iterator begin, input_iterator end)
    {
        for (auto it = begin; it != end; ++it)
            push_back(*it);
    }

    template <typename T>
    FrankList<T>::~FrankList()
    {
        auto* current = m_Head;
        while (current)
        {
            auto* temp = current;
            current    = current->next;
            delete temp;
        }
        m_Head  = nullptr;
        m_Tail  = nullptr;
        m_AHead = nullptr;
        m_ATail = nullptr;
    }

    template <typename T>
    void FrankList<T>::swap(FrankList<T>& other)
    {
        std::swap(m_Head, other.m_Head);
        std::swap(m_Tail, other.m_Tail);
        std::swap(m_AHead, other.m_AHead);
        std::swap(m_ATail, other.m_ATail);
    }

    template <typename T>
    typename FrankList<T>::size_type FrankList<T>::size() const
    {
        size_type len     = 0;
        auto*     current = m_Head;
        if (current)
        {
            while (++len && current->next)
                current = current->next;
        }
        return len;
    }

    template <typename T>
    bool FrankList<T>::empty() const
    {
        return !m_Head;
    }

    template <typename T>
    void FrankList<T>::resize(size_type new_size, const_reference init)
    {
        const auto len = size();
        if (new_size > len)
        {
            // If we're extending the list then just push_back()
            // new_size - len init elements.
            auto* current = m_Tail;
            for (auto i = 0; i < new_size - len; ++i)
                push_back(init);
        }
        else if (new_size < len)
        {
            // Else just detach starting from the tail going backwards.
            auto* current = m_Tail;
            for (auto i = 0; i < len - new_size; ++i)
            {
                detach_node(current);
                auto* prev = current;
                current    = current->prev;
                delete prev;
            }
        }
    }

    template <typename T>
    void FrankList<T>::clear() noexcept
    {
        auto* current = m_Head;
        if (current)
        {
            while (current)
            {
                auto* temp = current;
                current    = current->next;
                delete temp;
            }
            m_Head  = nullptr;
            m_Tail  = nullptr;
            m_AHead = nullptr;
            m_ATail = nullptr;
        }
    }

    template <typename T>
    void FrankList<T>::push_front(const_reference elem)
    {
        if (!m_Head)
            m_Head = new Node(elem);
        else
        {
            auto* current = m_Head;
            m_Head        = new Node(elem);
            m_Head->next  = current;
            current->prev = m_Head;
        }
    }

    template <typename T>
    void FrankList<T>::pop_front()
    {
        if (m_Head)
        {
            // Make our head's next to be our new head
            // and new head's previous to be null because
            // it is the head now.
            auto* temp   = m_Head;
            m_Head       = m_Head->next;
            m_Head->prev = nullptr;

            // We might be the first node.
            if (temp->desc)
                temp->desc->asc = temp->asc;
            temp->asc->desc = temp->desc;

            // Our node might be the head, or the
            // taill so update them.
            if (temp == m_AHead)
                m_AHead = temp->asc;
            else if (temp == m_ATail)
                m_ATail = temp->desc;

            delete temp;
        }
        else
            throw std::runtime_error("Tried calling pop_front() on an empty list.");
    }

    template <typename T>
    void FrankList<T>::push_back(const_reference elem)
    {
        auto* node = new Node(elem);
        if (!m_Head)
        {
            // If we don't have any node
            // then just create one and make it both
            // head and tail.
            m_Head = node;
            m_Tail = node;
        }
        else
        {
            // Else make the tail to point to our new
            // node and make our new node's previous
            // to point to the previous
            // head and update the tail.
            auto* current = m_Tail;
            current->next = node;
            node->prev    = current;
            m_Tail        = node;
        }

        // Sort the node inside our sorted arrangement.
        put_in_sorted_order(node);
    }

    template <typename T>
    void FrankList<T>::pop_back()
    {
        if (m_Tail)
        {
            // Make our new tail's next to be null and
            // and our tail to be our old tail's next
            // and finally update our tail pointer.
            auto* temp      = m_Tail;
            m_Tail          = m_Tail->prev;
            m_Tail->next    = nullptr;
            temp->desc->asc = temp->asc;

            // We might be the last node.
            if (temp->asc)
                temp->asc->desc = temp->desc;

            delete temp;
        }
        else
            throw std::runtime_error("Tried calling pop_back() on an empty list.");
    }

    template <typename T>
    typename FrankList<T>::const_reference FrankList<T>::front() const
    {
        return ((FrankList<T>*)this)->front();
    }

    template <typename T>
    typename FrankList<T>::reference FrankList<T>::front()
    {
        return m_Head->val;
    }

    template <typename T>
    typename FrankList<T>::const_reference FrankList<T>::back() const
    {
        return ((FrankList<T>*)this)->back();
    }

    template <typename T>
    typename FrankList<T>::reference FrankList<T>::back()
    {
        return m_Tail->val;
    }

    template <typename T>
    typename FrankList<T>::const_reference FrankList<T>::min() const
    {
        return ((FrankList<T>*)this)->min();
    }

    template <typename T>
    typename FrankList<T>::reference FrankList<T>::min()
    {
        return m_AHead->val;
    }

    template <typename T>
    typename FrankList<T>::const_reference FrankList<T>::max() const
    {
        return ((FrankList<T>*)this)->max();
    }

    template <typename T>
    typename FrankList<T>::reference FrankList<T>::max()
    {
        return m_ATail->val;
    }

    template <typename T>
    const FrankList<T>& FrankList<T>::operator=(FrankList<T> other)
    {
        swap(other);
        return *this;
    }

    template <typename T>
    const FrankList<T>& FrankList<T>::operator=(FrankList<T>&& other)
    {
        if (&other == this)
            return *this;

        swap(other);
        return *this;
    }

    template <typename T>
    const FrankList<T>& FrankList<T>::operator=(std::initializer_list<T> init)
    {
        FrankList<T> successor(init);
        swap(successor);
        return *this;
    }

    template <typename T>
    bool FrankList<T>::operator==(const FrankList<T>& other) const
    {
        if (size() != other.size())
            return false;

        auto it  = cbegin();
        auto it2 = other.cbegin();
        while (it != cend() && it2 != other.cend())
        {
            if (*it != *it)
                return false;
            ++it, ++it2;
        }
        return true;
    }

    /* ADDED BY ME */
    // Instead of implementing all the operators we can only implement == and <=> in C++20
    // which will add automatic support for all the others.
    template <typename T>
    auto FrankList<T>::operator<=>(const FrankList<T>& other) const
    {
        auto it  = cbegin();
        auto it2 = other.cbegin();

        // Iterate over the two lists simultaneously
        // and check if the current element of it is lesser or greater,
        // if lesser than immediately return strong::less, strong::greater
        // otherwise, if none is true then they're equal so proceed.
        while (it != cend() && it2 != other.cend())
        {
            if (*it < *it2)
                return std::strong_ordering::less;
            else if (*it > *it2)
                return std::strong_ordering::greater;

            ++it, ++it2;
        }

        // Here if it is an end iterator then it2 is lexicographcailly greater,
        // it otherwise.
        if (it != cend())
            return std::strong_ordering::greater;
        else if (it2 != other.cend())
            return std::strong_ordering::less;

        // If none is true then they're equal.
        return std::strong_ordering::equal;
    }
    /* ... */

    template <typename T>
    typename FrankList<T>::const_iterator FrankList<T>::cbegin() const
    {
        return const_iterator(m_Head);
    }

    template <typename T>
    typename FrankList<T>::const_iterator FrankList<T>::cend() const
    {
        return const_iterator(nullptr);
    }

    template <typename T>
    typename FrankList<T>::const_reverse_iterator FrankList<T>::crbegin() const
    {
        return const_reverse_iterator(m_Tail);
    }

    template <typename T>
    typename FrankList<T>::const_reverse_iterator FrankList<T>::crend() const
    {
        return const_reverse_iterator(nullptr);
    }

    template <typename T>
    typename FrankList<T>::const_asc_iterator FrankList<T>::cabegin() const
    {
        return const_asc_iterator(m_AHead);
    }

    template <typename T>
    typename FrankList<T>::const_asc_iterator FrankList<T>::caend() const
    {
        return const_asc_iterator(nullptr);
    }

    template <typename T>
    typename FrankList<T>::const_desc_iterator FrankList<T>::cdbegin() const
    {
        return const_desc_iterator(m_ATail);
    }

    template <typename T>
    typename FrankList<T>::const_desc_iterator FrankList<T>::cdend() const
    {
        return const_desc_iterator(nullptr);
    }

    template <typename T>
    typename FrankList<T>::const_multi_iterator FrankList<T>::cmbegin() const
    {
        return const_multi_iterator(m_Head);
    }

    template <typename T>
    typename FrankList<T>::const_multi_iterator FrankList<T>::cmend() const
    {
        return const_multi_iterator(nullptr);
    }

    template <typename T>
    typename FrankList<T>::const_multi_iterator FrankList<T>::cmabegin() const
    {
        auto it = const_multi_iterator(m_AHead);
        it.chmod();
        return it;
    }

    template <typename T>
    typename FrankList<T>::const_multi_iterator FrankList<T>::cmaend() const
    {
        auto it = const_multi_iterator(nullptr);
        it.chmod();
        return it;
    }

    template <typename T>
    typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrbegin() const
    {
        return const_multi_reverse_iterator(m_Tail);
    }

    template <typename T>
    typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrend() const
    {
        return const_multi_reverse_iterator(nullptr);
    }

    template <typename T>
    typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdbegin() const
    {
        return const_multi_reverse_iterator(m_ATail);
    }

    template <typename T>
    typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdend() const
    {
        return const_multi_reverse_iterator(nullptr);
    }

    /* ADDED BY ME */
    // The reason why I added the const overload version of begin, end, rbegin, and rend
    // is because, first, it's a requirement by the C++ standard, and second,
    // because const range-based loops would not work. 
    template <typename T>
    typename FrankList<T>::const_iterator FrankList<T>::begin() const
    {
        return cbegin();
    }

    template <typename T>
    typename FrankList<T>::const_iterator FrankList<T>::end() const
    {
        return cend();
    }

    template <typename T>
    typename FrankList<T>::const_reverse_iterator FrankList<T>::rbegin() const
    {
        return crbegin();
    }

    template <typename T>
    typename FrankList<T>::const_reverse_iterator FrankList<T>::rend() const
    {
        return crend();
    }
    /* ... */

    template <typename T>
    typename FrankList<T>::iterator FrankList<T>::begin()
    {
        return cbegin();
    }

    template <typename T>
    typename FrankList<T>::iterator FrankList<T>::end()
    {
        return cend();
    }

    template <typename T>
    typename FrankList<T>::reverse_iterator FrankList<T>::rbegin()
    {
        return crbegin();
    }

    template <typename T>
    typename FrankList<T>::reverse_iterator FrankList<T>::rend()
    {
        return crend();
    }

    template <typename T>
    typename FrankList<T>::asc_iterator FrankList<T>::abegin()
    {
        return cabegin();
    }

    template <typename T>
    typename FrankList<T>::asc_iterator FrankList<T>::aend()
    {
        return caend();
    }

    template <typename T>
    typename FrankList<T>::desc_iterator FrankList<T>::dbegin()
    {
        return cdbegin();
    }

    template <typename T>
    typename FrankList<T>::desc_iterator FrankList<T>::dend()
    {
        return cdend();
    }

    template <typename T>
    typename FrankList<T>::multi_iterator FrankList<T>::mbegin()
    {
        return cmbegin();
    }

    template <typename T>
    typename FrankList<T>::multi_iterator FrankList<T>::mend()
    {
        return cmend();
    }

    template <typename T>
    typename FrankList<T>::multi_iterator FrankList<T>::mabegin()
    {
        return cmabegin();
    }

    template <typename T>
    typename FrankList<T>::multi_iterator FrankList<T>::maend()
    {
        return cmaend();
    }

    template <typename T>
    typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrbegin()
    {
        return cmrbegin();
    }

    template <typename T>
    typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrend()
    {
        return cmrend();
    }

    template <typename T>
    typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrdbegin()
    {
        return cmrdbegin();
    }

    template <typename T>
    typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrdend()
    {
        return cmrdend();
    }

    template <typename T>
    template <typename iter>
    iter FrankList<T>::insert(iter pos, size_type size, const_reference val)
    {
        auto current_pos = pos;
        for (auto i = 0; i < size; ++i)
            current_pos = insert_def(current_pos, val);
        return pos;
    }

    template <typename T>
    template <typename iter>
    iter FrankList<T>::insert(iter pos, std::initializer_list<T> init)
    {
        auto current_pos = pos;
        for (const auto& e : init)
            current_pos = insert_def(current_pos, e);
        return pos;
    }

    template <typename T>
    template <typename iter, typename input_iterator>
    iter FrankList<T>::insert(iter pos, input_iterator begin, input_iterator end)
    {
        auto current_pos = pos;
        for (auto it = begin; it != end; ++it)
            current_pos = insert_def(current_pos, *it);
        return pos;
    }

    template <typename T>
    template <typename iter>
    iter FrankList<T>::erase(iter pos)
    {
        Node* node = nullptr;

        // Check if begin is not any end iterator because
        // end here is just nullptr, so if we have an end iterator
        // as our starting point then replace it with the appropriate
        // tail pointer.
        if (pos == cend())
            node = m_Tail;
        else if (pos == crend())
            node = m_Head;
        else if (pos == caend())
            node = m_ATail;
        else if (pos == cdend())
            node = m_AHead;
        else if (pos == cmend())
        {
            if constexpr (
                std::is_base_of_v<const_multi_iterator, iter> || std::is_base_of_v<const_multi_reverse_iterator, iter>)
            {
                if (pos.mode)
                    node = m_Tail;
                else
                    node = m_ATail;
            }
        }
        else if (pos == cmrend())
        {
            if constexpr (
                std::is_base_of_v<const_multi_iterator, iter> || std::is_base_of_v<const_multi_reverse_iterator, iter>)
            {
                if (pos.mode)
                    node = m_Head;
                else
                    node = m_AHead;
            }
        }
        else
            node = pos.m_Ptr;

        // Simply detach the node and then delete the node.
        detach_node(node);
        delete node;
        return pos;
    }

    template <typename T>
    template <typename iter>
    iter FrankList<T>::erase(iter begin, iter end)
    {
        auto  it   = begin;
        Node* node = nullptr;

        // Check if begin is not any end iterator because
        // end here is just nullptr, so if we have an end iterator
        // as our starting point then replace it with the appropriate
        // tail pointer.
        if (begin == cend())
            node = m_Tail;
        else if (begin == crend())
            node = m_Head;
        else if (begin == caend())
            node = m_ATail;
        else if (begin == cdend())
            node = m_AHead;
        else if (begin == cmend())
        {
            if constexpr (
                std::is_base_of_v<const_multi_iterator, iter> || std::is_base_of_v<const_multi_reverse_iterator, iter>)
            {
                if (begin.mode)
                    node = m_Tail;
                else
                    node = m_ATail;
            }
        }
        else if (begin == cmrend())
        {
            if constexpr (
                std::is_base_of_v<const_multi_iterator, iter> || std::is_base_of_v<const_multi_reverse_iterator, iter>)
            {
                if (begin.mode)
                    node = m_Head;
                else
                    node = m_AHead;
            }
        }
        else
            node = begin.m_Ptr;

        // Iterate over the supplied iterator range,
        // increment first, then detach the node belonging to that iterator,
        // delete it and assign node to be our current iterator's (now incremented) node.
        while (it != end)
        {
            ++it;
            detach_node(node);
            delete node;
            node = it.m_Ptr;
        }
        return end;
    }

    template <typename T>
    typename FrankList<T>::iterator FrankList<T>::remove(const_reference val)
    {
        // Create an iterator from our current tail for comparison.
        auto end_it = iterator(m_Tail);
        auto it     = begin();

        // Iterate over the container and check if they match to val,
        // if they do then grab the node, detach it and attach to to the tail
        // until we reach the end.
        while (it != end_it)
        {
            auto* node = it.m_Ptr;
            ++it;
            if (node->val == val)
            {
                detach_node(node);
                m_Tail->next = node;
                node->prev   = m_Tail;
                m_Tail       = node;
            }
        }

        // After iterating until the previous end (end_it), it might be possible
        // that end_it is also equal to val, so check for that too, otherwise
        // go past it.
        if (*end_it != val)
            ++end_it;
        return end_it;
    }

    template <typename T>
    template <typename unary_predicate>
    typename FrankList<T>::iterator FrankList<T>::remove_if(unary_predicate fn)
    {
        // Create an iterator from our current tail for comparison.
        auto end_it = iterator(m_Tail);
        auto it     = begin();

        // Iterate over the container and check if they match to val,
        // if they do then grab the node, detach it and attach to to the tail
        // until we reach the end.
        while (it != end_it)
        {
            auto* node = it.m_Ptr;
            ++it;
            if (fn(node->val))
            {
                detach_node(node);
                m_Tail->next = node;
                node->prev   = m_Tail;
                m_Tail       = node;
            }
        }

        // After iterating until the previous end (end_it), it might be possible
        // that end_it is also equal to val, so check for that too, otherwise
        // go past it.
        if (!fn(*end_it))
            ++end_it;
        return end_it;
    }

    template <typename T>
    void FrankList<T>::reverse()
    {
        Node* temp    = nullptr;
        Node* current = m_Head;

        // Traverse the list and swap the next and
        // previous pointers for each node.
        while (current != nullptr)
        {
            temp          = current->prev;
            current->prev = current->next;
            current->next = temp;
            current       = current->prev;
        }

        // Update the head to point to the
        // new first node in the reversed list.
        if (temp != nullptr)
            m_Head = temp->prev;
    }

    template <typename T>
    void FrankList<T>::sort(bool reversed)
    {
        if (empty())
            return;

        // We sort the list by simply iterating over
        // the sorted order using asc_iterator and
        // desc_iterator (if reversed is true) and simply
        // assign the next and prev pointers to asc and desc
        // (or vice versa if reversed is true).
        // We also do the exact same thing with m_Head and m_Tail.
        if (reversed)
        {
            for (auto it = dbegin(); it != dend(); ++it)
            {
                it.m_Ptr->next = it.m_Ptr->desc;
                it.m_Ptr->prev = it.m_Ptr->asc;
            }
            m_Head = m_ATail;
            m_Tail = m_AHead;
        }
        else
        {
            for (auto it = abegin(); it != aend(); ++it)
            {
                it.m_Ptr->next = it.m_Ptr->asc;
                it.m_Ptr->prev = it.m_Ptr->desc;
            }
            m_Head = m_AHead;
            m_Tail = m_ATail;
        }
    }

    template <typename T>
    typename FrankList<T>::iterator FrankList<T>::find(const_reference elem)
    {
        for (auto it = begin(); it != end(); ++it)
        {
            if (*it == elem)
            {
                // If our node is not the left most node,
                // then move it once to the left and then
                // create a new iterator from it, and finally
                // return it.
                auto* node = it.m_Ptr;
                if (it != begin())
                    organize_left(node);
                return decltype(it)(node);
            }
        }
        return end();
    }

    template <typename T>
    typename FrankList<T>::iterator FrankList<T>::rfind(const_reference elem)
    {
        for (auto it = rbegin(); it != rend(); ++it)
        {
            if (*it == elem)
            {
                // If our node is not the right most node,
                // then move it once to the right and then
                // create a new iterator from it, and finally
                // return it.
                auto* node = it.m_Ptr;
                if (it != rbegin())
                    organize_right(node);
                return decltype(it)(node);
            }
        }
        return rend();
    }

    template <typename T>
    template <typename unary_predicate>
    void FrankList<T>::traverse(unary_predicate fn, bool sorted, bool reversed)
    {
        // Simply traverse using the provided iterators
        // based on the parameters and assume fn is a
        // function that returns nothing and takes a single
        // parameter of type 'reference' or 'value_type' (const versions also).
        if (sorted)
        {
            if (reversed)
            {
                for (auto it = dbegin(); it != dend(); ++it)
                    fn(*it);
            }
            else
            {
                for (auto it = abegin(); it != aend(); ++it)
                    fn(*it);
            }
        }
        else
        {
            if (reversed)
            {
                for (auto it = rbegin(); it != rend(); ++it)
                    fn(*it);
            }
            else
            {
                for (auto& e : *this)
                    fn(e);
            }
        }
    }

    template <typename T>
    void FrankList<T>::print(bool sorted, bool reversed) const
    {
        // Almost identical to traverse() except we do not
        // call a function on the element
        // instead we print the element.
        if (sorted)
        {
            if (reversed)
            {
                std::cout << "[ ";
                for (auto it = cdbegin(); it != cdend(); ++it)
                {
                    if (std::next(it) != cdend())
                        std::cout << *it << ", ";
                    else
                        std::cout << *it;
                }
                std::cout << " ]";
            }
            else
            {
                std::cout << "[ ";
                for (auto it = cabegin(); it != caend(); ++it)
                {
                    if (std::next(it) != caend())
                        std::cout << *it << ", ";
                    else
                        std::cout << *it;
                }
                std::cout << " ]";
            }
        }
        else
        {
            if (reversed)
            {
                std::cout << "[ ";
                for (auto it = crbegin(); it != crend(); ++it)
                {
                    if (std::next(it) != crend())
                        std::cout << *it << ", ";
                    else
                        std::cout << *it;
                }
                std::cout << " ]";
            }
            else
            {
                std::cout << "[ ";
                for (auto it = cbegin(); it != cend(); ++it)
                {
                    if (std::next(it) != cend())
                        std::cout << *it << ", ";
                    else
                        std::cout << *it;
                }
                std::cout << " ]";
            }
        }
    }

    template <typename T>
    void FrankList<T>::put_in_sorted_order(Node* ptr)
    {
        if (m_AHead)
        {
            // Find the largest node in the list against our node.
            auto* current = m_AHead;
            while (current->asc && ptr->val > current->val)
                current = current->asc;

            // Check to see if our node is lesser or equal to the
            // largest found node.
            if (ptr->val <= current->val)
            {
                // If it is then fit it in-between our largest
                // node and its predecessor.
                auto* current_desc = current->desc;
                current->desc      = ptr;
                ptr->asc           = current;
                ptr->desc          = current_desc;

                // Here current might be the head so it has no
                // descendor so check for it.
                if (current_desc)
                    current_desc->asc = ptr;

                // Our element might be lesser than
                // our head so update the head.
                if (m_AHead == current)
                    m_AHead = ptr;
            }
            else
            {
                // Else set our node to be the list's largest node's
                // successor and make our node's predecessor to be
                // the previous largest node.
                current->asc = ptr;
                ptr->desc    = current;

                // Our element might be greater than
                // our head tail so update the tail.
                if (m_ATail == current)
                    m_ATail = ptr;
            }
        }
        else
        {
            m_AHead = ptr;
            m_ATail = ptr;
        }
    }

    template <typename T>
    void FrankList<T>::organize_left(Node* node)
    {
        // Grab our current node's next and previous nodes.
        auto* prev_node = node->prev;
        auto* next_node = node->next;

        // Swap our node to point to our previous node
        // and our previous node's previous to point
        // to our node.
        node->prev = prev_node->prev;
        node->next = prev_node;

        // If we have a previous then make
        // the previous' next to point to our node,
        // otherwise it's the head so make our head
        // point to our node.
        if (prev_node->prev)
            prev_node->prev->next = node;
        else
            m_Head = node;

        // Next swap our node and the previous
        // node in our previous node's perspective.
        prev_node->prev = node;
        prev_node->next = next_node;

        // Afterwhich check if our node had a next,
        // if it did then make the next's node's previous
        // to be our previous node, otherwise its the
        // tail so make the tail point to our previous node.
        if (next_node)
            next_node->prev = prev_node;
        else
            m_Tail = prev_node;
    }

    template <typename T>
    void FrankList<T>::organize_right(Node* node)
    {
        // Grab our current node's next and previous nodes.
        auto* prev_node = node->prev;
        auto* next_node = node->next;

        // Swap our node to point to its previous next's next
        // node and then make the preivous point to its previous next.
        node->prev = next_node;
        node->next = next_node->next;

        // If we have a next then make
        // the next's previous to point to our node,
        // otherwise it's the tail so make our tail
        // point to our node.
        if (next_node->next)
            next_node->next->prev = node;
        else
            m_Tail = node;

        // Next swap our next node's next to point
        // to our current node and its previous to
        // be our node's previous.
        next_node->next = node;
        next_node->prev = prev_node;

        // Afterwhich check if our node had a previous,
        // if it did then make previous's node's next
        // to be our node's next, otherwise its the head
        // head point to our node's next node.
        if (prev_node)
            prev_node->next = next_node;
        else
            m_Head = next_node;
    }

    /* ADDED BY ME */
    // Handy private utility function that does what the
    // name suggests.
    // It effectively detaches the given node
    // while maintaing the correct order
    // both in regular and sorted ordering.
    template <typename T>
    void FrankList<T>::detach_node(Node* node) noexcept
    {
        if (node->prev)
            node->prev->next = node->next;
        else
            m_Head = node->next;

        if (node->next)
            node->next->prev = node->prev;
        else
            m_Tail = node->prev;

        if (node->desc)
            node->desc->asc = node->asc;
        else
            m_AHead = node->asc;

        if (node->asc)
            node->asc->desc = node->desc;
        else
            m_ATail = node->desc;

        node->next = nullptr;
        node->prev = nullptr;
        node->asc  = nullptr;
        node->desc = nullptr;
    }
    /* ... */

    template <typename T>
    template <typename iter>
    iter FrankList<T>::insert_def(iter pos, const_reference val)
    {
        auto* node = pos.m_Ptr;

        // Check if begin is not any end iterator because
        // end here is just nullptr, so if we have an end iterator
        // as our starting point then replace it with the appropriate
        // tail pointer.
        if (pos == cend())
            node = m_Tail;
        else if (pos == crend())
            node = m_Head;
        else if (pos == caend())
            node = m_ATail;
        else if (pos == cdend())
            node = m_AHead;
        else if (pos == cmend())
        {
            if constexpr (
                std::is_base_of_v<const_multi_iterator, iter> || std::is_base_of_v<const_multi_reverse_iterator, iter>)
            {
                if (pos.mode)
                    node = m_Tail;
                else
                    node = m_ATail;
            }
        }
        else if (pos == cmrend())
        {
            if constexpr (
                std::is_base_of_v<const_multi_iterator, iter> || std::is_base_of_v<const_multi_reverse_iterator, iter>)
            {
                if (pos.mode)
                    node = m_Head;
                else
                    node = m_AHead;
            }
        }
        else
            node = pos.m_Ptr;

        auto* new_node = new Node(val);

        // Check if our position node is valid.
        if (node)
        {
            // Check if it's the tail.
            if (node == m_Tail)
            {
                // If it is then just attach the new node to the tail and
                // then make it the new tail.
                auto* prev_next = node->next;
                node->next      = new_node;
                new_node->next  = prev_next;
                new_node->prev  = node;
                m_Tail          = new_node;
            }
            else
            {
                // Else attach node to new_node instead.
                new_node->next = node;
                new_node->prev = node->prev;
                if (node->prev)
                    node->prev->next = new_node;
                node->prev = new_node;

                // node might also be the head so update the head if it is.
                if (node == m_Head)
                    m_Head = new_node;
            }
        }
        else
        {
            // If node is invalid then either the list is empty
            // or the supplied iterator is invalid.
            if (!m_Head)
            {
                m_Head = new_node;
                m_Tail = new_node;
            }
            else
                throw std::invalid_argument("Supplied iterator is invalid.");
        }

        // Sort the new node.
        put_in_sorted_order(new_node);
        return iter(new_node->next);
    }

    template <typename T>
    template <typename iter>
    iter FrankList<T>::insert_rev(iter pos, const_reference val)
    {
        auto* node = pos.m_Ptr;

        // Check if begin is not any end iterator because
        // end here is just nullptr, so if we have an end iterator
        // as our starting point then replace it with the appropriate
        // tail pointer.
        if (pos == cend())
            node = m_Tail;
        else if (pos == crend())
            node = m_Head;
        else if (pos == caend())
            node = m_ATail;
        else if (pos == cdend())
            node = m_AHead;
        else if (pos == cmend())
        {
            if constexpr (
                std::is_base_of_v<const_multi_iterator, iter> || std::is_base_of_v<const_multi_reverse_iterator, iter>)
            {
                if (pos.mode)
                    node = m_Tail;
                else
                    node = m_ATail;
            }
        }
        else if (pos == cmrend())
        {
            if constexpr (
                std::is_base_of_v<const_multi_iterator, iter> || std::is_base_of_v<const_multi_reverse_iterator, iter>)
            {
                if (pos.mode)
                    node = m_Head;
                else
                    node = m_AHead;
            }
        }
        else
            node = pos.m_Ptr;

        auto* new_node = new Node(val);

        // Check if our position node is valid.
        if (node)
        {
            // Check if it's the tail.
            if (node == m_Tail)
            {
                // If it is then just attach the new node to the tail and
                // then make it the new tail.
                auto* prev_next = node->next;
                node->next      = new_node;
                new_node->next  = prev_next;
                new_node->prev  = node;
                m_Tail          = new_node;
            }
            else
            {
                // Else attach node to new_node instead.
                new_node->next = node;
                new_node->prev = node->prev;
                if (node->prev)
                    node->prev->next = new_node;
                node->prev = new_node;

                // node might also be the head so update the head if it is.
                if (node == m_Head)
                    m_Head = new_node;
            }
        }
        else
        {
            // If node is invalid then either the list is empty
            // or the supplied iterator is invalid.
            if (!m_Head)
            {
                m_Head = new_node;
                m_Tail = new_node;
            }
            else
                throw std::invalid_argument("Supplied iterator is invalid.");
        }

        // Sort the new node.
        put_in_sorted_order(new_node);
        return iter(new_node->prev);
    }

    template <typename U>
    std::ostream& operator<<(std::ostream& stream, const FrankList<U>& other)
    {
        stream << "[ ";
        for (auto it = other.cbegin(); it != other.cend(); ++it)
        {
            if (std::next(it) != other.cend())
                std::cout << *it << ", ";
            else
                std::cout << *it;
        }
        stream << " ]";
        return stream;
    }
} // namespace vhuk

#endif // FRANKLIST_IMPL_H
