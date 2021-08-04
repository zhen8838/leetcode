#pragma once
#include <tuple>
#include <type_traits>

template <typename T, typename... TArgs>
decltype(void(T{std::declval<TArgs>()...}), std::true_type{}) test_is_braces_constructible(int);

template <typename, typename...>
std::false_type test_is_braces_constructible(...);

template <typename T, typename... TArgs>
using is_braces_constructible = decltype(test_is_braces_constructible<T, TArgs...>(0));

struct any_type
{
  template <typename T>
  constexpr operator T(); // non explicit
};

template <typename T>
constexpr auto to_tuple(T &&object) noexcept
{
  using type = std::decay_t<T>;
  if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type>{})
  {
    auto &&[p1, p2, p3, p4, p5, p6, p7, p8, p9, p10] = std::forward<T>(object);
    return std::tuple(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
  }
  else if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type>{})
  {
    auto &&[p1, p2, p3, p4, p5, p6, p7, p8, p9] = std::forward<T>(object);
    return std::tuple(p1, p2, p3, p4, p5, p6, p7, p8, p9);
  }
  else if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type>{})
  {
    auto &&[p1, p2, p3, p4, p5, p6, p7, p8] = std::forward<T>(object);
    return std::tuple(p1, p2, p3, p4, p5, p6, p7, p8);
  }
  else if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type, any_type, any_type, any_type>{})
  {
    auto &&[p1, p2, p3, p4, p5, p6, p7] = std::forward<T>(object);
    return std::tuple(p1, p2, p3, p4, p5, p6, p7);
  }
  else if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type, any_type, any_type>{})
  {
    auto &&[p1, p2, p3, p4, p5, p6] = std::forward<T>(object);
    return std::tuple(p1, p2, p3, p4, p5, p6);
  }
  else if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type, any_type>{})
  {
    auto &&[p1, p2, p3, p4, p5] = std::forward<T>(object);
    return std::tuple(p1, p2, p3, p4, p5);
  }
  else if constexpr (is_braces_constructible<type, any_type, any_type, any_type, any_type>{})
  {
    auto &&[p1, p2, p3, p4] = std::forward<T>(object);
    return std::tuple(p1, p2, p3, p4);
  }
  else if constexpr (is_braces_constructible<type, any_type, any_type, any_type>{})
  {
    auto &&[p1, p2, p3] = std::forward<T>(object);
    return std::tuple(p1, p2, p3);
  }
  else if constexpr (is_braces_constructible<type, any_type, any_type>{})
  {
    auto &&[p1, p2] = std::forward<T>(object);
    return std::tuple(p1, p2);
  }
  else if constexpr (is_braces_constructible<type, any_type>{})
  {
    auto &&[p1] = std::forward<T>(object);
    return std::tuple(p1);
  }
  else
  {
    return std::tuple{};
  }
}