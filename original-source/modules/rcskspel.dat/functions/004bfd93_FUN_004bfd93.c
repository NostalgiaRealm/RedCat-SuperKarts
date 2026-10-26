/*
 * FUN_004bfd93 at 004bfd93
 * undefined FUN_004bfd93(void)
 * Address ranges: 004bfd93-004bfdae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

exception * __thiscall FUN_004bfd93(exception *param_1,byte param_2)

{
  exception::~exception(param_1);
  if ((param_2 & 1) != 0) {
    FUN_004bc150(param_1);
  }
  return param_1;
}

