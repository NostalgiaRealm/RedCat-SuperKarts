/*
 * FUN_00419221 at 00419221
 * undefined __cdecl FUN_00419221(uint * param_1)
 * Address ranges: 00419221-00419262
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00419221(uint *param_1)

{
  size_t sVar1;
  
  sVar1 = _strlen((char *)param_1);
  if (400 < sVar1) {
    FUN_0040187a((byte *)s__s__d_____set_ownedit_keys_allow_00435e98);
  }
  FUN_0041f7a0((uint *)&DAT_0043de00,param_1);
  return;
}

