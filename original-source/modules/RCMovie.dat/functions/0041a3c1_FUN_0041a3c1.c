/*
 * FUN_0041a3c1 at 0041a3c1
 * undefined __cdecl FUN_0041a3c1(uint * param_1)
 * Address ranges: 0041a3c1-0041a402
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041a3c1(uint *param_1)

{
  size_t sVar1;
  
  sVar1 = _strlen((char *)param_1);
  if (400 < sVar1) {
    FUN_0040187a((byte *)s__s__d_____set_edit_keys_allowed__0043628c);
  }
  FUN_0041f7a0((uint *)&DAT_0043df98,param_1);
  return;
}

