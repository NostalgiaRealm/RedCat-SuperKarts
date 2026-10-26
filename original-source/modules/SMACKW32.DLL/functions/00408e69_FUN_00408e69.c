/*
 * FUN_00408e69 at 00408e69
 * uint __fastcall FUN_00408e69(undefined4 param_1, uint param_2)
 * Address ranges: 00408e69-00408ebb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_00408e69(undefined4 param_1,uint param_2)

{
  uint in_EAX;
  ushort in_FPUControlWord;
  undefined4 local_18;
  
  local_18 = 0;
  if ((DAT_0040f0c4 != '\0') && (local_18 = (uint)in_FPUControlWord, param_2 != 0)) {
    local_18 = ~param_2 & local_18 | param_2 & in_EAX & 0xffff;
  }
  return local_18;
}

