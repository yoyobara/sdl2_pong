template <class... Ts> struct overloaded : Ts... {
  using Ts::operator()...;
};

// C++17 deduction guide
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;