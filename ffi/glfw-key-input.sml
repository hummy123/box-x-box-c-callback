structure Key = struct
  type window = MLton.Pointer.t

  val isPressedI = _import "isPressedI" public : unit -> bool;
  val isPressedJ = _import "isPressedJ" public : unit -> bool;
  val isPressedK = _import "isPressedK" public : unit -> bool;
  val isPressedL = _import "isPressedL" public : unit -> bool;
  val setCallback = _import "setKeyCallback" public : window -> unit;
end
