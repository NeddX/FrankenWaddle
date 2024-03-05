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
        base_iterator::m_Ptr = base_iterator::m_Ptr->desc;
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
    FrankList<T>::FrankList(const FrankList<T>& other)
    {
        for (const auto& e : other)
            push_back(e);
    }

    template <typename T>
    FrankList<T>::FrankList(FrankList<T>&& other) : FrankList()
    {
        std::swap(m_Head, other.m_Head);
        std::swap(m_Tail, other.m_Tail);
        std::swap(m_AHead, other.m_AHead);
        std::swap(m_ATail, other.m_ATail);
    }

    template <typename T>
    FrankList<T>::FrankList(const std::initializer_list<value_type>& list) : FrankList<T>()
    {
        insert(end(), list.begin(), list.end());
    }

    template <typename T>
    template <typename input_iterator>
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
        while (current->next && ++len)
            current = current->next;
        return len;
    }

    template <typename T>
    bool FrankList<T>::empty() const
    {
        return m_Head;
    }

    template <typename T>
    void FrankList<T>::clear() noexcept
    {
        // Tihs is not supposed to be noexcept because the
        // delete operator is capable of throwing an exception.
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
    typename FrankList<T>::const_iterator FrankList<T>::cbegin() const
    {
        return const_iterator(m_Head);
    }

    template <typename T>
    typename FrankList<T>::const_iterator FrankList<T>::cend() const
    {
        return const_iterator(m_Tail);
    }

    template <typename T>
    typename FrankList<T>::const_reverse_iterator FrankList<T>::crbegin() const
    {
        return const_reverse_iterator(m_Tail);
    }

    template <typename T>
    typename FrankList<T>::const_reverse_iterator FrankList<T>::crend() const
    {
        return const_reverse_iterator(m_Head);
    }

    template <typename T>
    typename FrankList<T>::const_asc_iterator FrankList<T>::cabegin() const
    {
        return const_asc_iterator(m_AHead);
    }

    template <typename T>
    typename FrankList<T>::const_asc_iterator FrankList<T>::caend() const
    {
        return const_asc_iterator(m_ATail);
    }

    template <typename T>
    typename FrankList<T>::const_desc_iterator FrankList<T>::cdbegin() const
    {
        return const_desc_iterator(m_ATail);
    }

    template <typename T>
    typename FrankList<T>::const_desc_iterator FrankList<T>::cdend() const
    {
        return const_desc_iterator(m_AHead);
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
        return iterator(m_Head);
    }

    template <typename T>
    typename FrankList<T>::iterator FrankList<T>::end()
    {
        return iterator(m_Tail);
    }

    template <typename T>
    typename FrankList<T>::reverse_iterator FrankList<T>::rbegin()
    {
        return reverse_iterator(m_Tail);
    }

    template <typename T>
    typename FrankList<T>::reverse_iterator FrankList<T>::rend()
    {
        return reverse_iterator(m_Head);
    }

    template <typename T>
    typename FrankList<T>::asc_iterator FrankList<T>::abegin()
    {
        return asc_iterator(m_AHead);
    }

    template <typename T>
    typename FrankList<T>::asc_iterator FrankList<T>::aend()
    {
        return asc_iterator(m_ATail);
    }

    template <typename T>
    typename FrankList<T>::desc_iterator FrankList<T>::dbegin()
    {
        return desc_iterator(m_ATail);
    }

    template <typename T>
    typename FrankList<T>::desc_iterator FrankList<T>::dend()
    {
        return desc_iterator(m_AHead);
    }

    template <typename T>
    template <typename iter>
    iter FrankList<T>::insert(iter pos, size_type size, const_reference val)
    {
        Node* node = pos.m_Ptr;
        for (auto i = 0; i < size; ++i)
        {
            auto* prev_next = node->next;
            auto* new_node  = new Node(val);
            node->next      = new_node;
            new_node->next  = prev_next;
            node            = new_node;
            put_in_sorted_order(new_node);
        }
        return pos;
    }

    template <typename T>
    template <typename iter>
    iter FrankList<T>::insert(iter pos, std::initializer_list<T> init)
    {
        Node* node = pos.m_Ptr;
        for (const auto& e : init)
        {
            auto* prev_next = node->next;
            auto* new_node  = new Node(e);
            node->next      = new_node;
            new_node->next  = prev_next;
            node            = new_node;
            put_in_sorted_order(new_node);
        }
        return pos;
    }

    template <typename T>
    template <typename iter, typename input_iterator>
    iter FrankList<T>::insert(iter pos, input_iterator begin, input_iterator end)
    {
        Node* node = pos.m_Ptr;
        for (auto it = begin; it != end; ++it)
        {
            auto* prev_next = node->next;
            auto* new_node  = new Node(*it);
            node->next      = new_node;
            new_node->next  = prev_next;
            node            = new_node;
            put_in_sorted_order(new_node);
        }
        return pos;
    }

    template <typename T>
    template <typename iter>
    iter FrankList<T>::erase(iter pos)
    {
        Node* node       = pos.m_Ptr;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->desc->asc  = node->asc;
        node->asc->desc  = node->desc;
        delete node;
        return pos;
    }

    template <typename T>
    template <typename iter>
    iter FrankList<T>::erase(iter begin, iter end)
    {
        Node* prev_node      = begin.m_Ptr->prev;
        Node* next_node      = end.m_Ptr->next;
        Node* prev_node_asc  = prev_node->asc;
        Node* next_node_desc = next_node->desc;

        prev_node->next = next_node;
        next_node->prev = prev_node;

        for (auto it = begin; it != end; ++it)
            delete it.m_Ptr;
        return begin;
    }

    template <typename T>
    typename FrankList<T>::size_type FrankList<T>::remove(const_reference val)
    {
        size_type count = 0;
        return count;
    }

    template <typename T>
    typename FrankList<T>::iterator FrankList<T>::find(const_reference elem)
    {
        for (auto it = begin(); it != end(); ++it)
        {
            if (*it == elem)
                return it;
        }
    }

    template <typename T>
    typename FrankList<T>::iterator FrankList<T>::rfind(const_reference elem)
    {
        for (auto it = rbegin(); it != rend(); ++it)
        {
            if (*it == elem)
                return it;
        }
    }

    template <typename T>
    template <typename unary_predicate>
    void FrankList<T>::traverse(unary_predicate fn, bool sorted, bool reversed)
    {
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
    void FrankList<T>::print(bool sorted, bool reversed)
    {
        if (sorted)
        {
            if (reversed)
            {
                for (auto it = dbegin(); it != dend(); ++it) {}
            }
            else
            {
                for (auto it = abegin(); it != aend(); ++it) {}
            }
        }
        else
        {
            if (reversed)
            {
                for (auto it = rbegin(); it != rend(); ++it) {}
            }
            else
            {
                for (auto& e : *this) {}
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

            // Check to see if our node is lesser than the
            // largest found node.
            if (ptr->val < current->val)
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
} // namespace vhuk

#endif // FRANKLIST_IMPL_H
