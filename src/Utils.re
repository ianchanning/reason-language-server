let startsWith = (s, prefix) => {
  let p = String.length(prefix);
  p <= String.length(s) && String.sub(s, 0, p) == prefix;
};

let sliceToEnd = (s, start) => {
  let l = String.length(s);
  start <= l ? String.sub(s, start, l - start) : s;
};

let chopPrefix = (s, prefix) => sliceToEnd(s, String.length(prefix));

let filterMap = (fn, items) =>
  List.fold_left(
    (results, item) =>
      switch (fn(item)) {
      | None => results
      | Some(x) => [x, ...results]
      },
    [],
    items
  );

let rec find = (fn, items) => {
  switch items {
  | [] => None
  | [one, ...rest] => switch (fn(one)) {
  | None => find(fn, rest)
  | Some(x) => Some(x)
  }
  }
};