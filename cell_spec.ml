open Core.Std
open Fspec_api

let cell_struct = Ir.Str ("cell", [])

let fun_types =
  String.Map.of_alist_exn
    ["alloc", {ret_type = Sint32;
               arg_types = [Ptr (Ptr cell_struct)];
               lemmas_before = [];
               lemmas_after = [];
               leaks = [on_rez_nz_leak "cellp(_, _)" ~id:"cellp"];};
     "full", {ret_type = Sint32;
              arg_types = [Ptr (Ptr cell_struct)];
              lemmas_before = [];
              lemmas_after = [];
              leaks = [];};
     "push", {ret_type = Sint32;
              arg_types = [Ptr (Ptr cell_struct);
                           Sint32];
              lemmas_before = [];
              lemmas_after = [];
              leaks = [];};
     "pop", {ret_type = Sint32;
             arg_types = [Ptr (Ptr cell_struct)];
             lemmas_before = [];
             lemmas_after = [];
             leaks = [];};
     "invariant_consume", {ret_type = Void;
                           arg_types = [Ptr (Ptr cell_struct)];
                           lemmas_before = [];
                           lemmas_after = [];
                           leaks = [remove_leak "cellp"];};
     "invariant_produce", {ret_type = Void;
                           arg_types = [Ptr (Ptr cell_struct)];
                           lemmas_before = [];
                           lemmas_after = [];
                           leaks = [leak "cellp(_, _)" ~id:"cellp"];};]

let fixpoints =
  String.Map.of_alist_exn []

module Iface : Fspec_api.Spec =
struct
  let preamble = In_channel.read_all "preamble.tmpl"
  let fun_types = fun_types
  let fixpoints = fixpoints
  let boundary_fun = "invariant_consume"
end

(* Register the module *)
let () =
  Fspec_api.spec := Some (module Iface) ;
