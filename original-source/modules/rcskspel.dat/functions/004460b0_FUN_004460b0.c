/*
 * FUN_004460b0 at 004460b0
 * undefined FUN_004460b0(void)
 * Address ranges: 004460b0-004460f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * __fastcall FUN_004460b0(undefined4 *param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 local_1;
  
  *param_1 = &PTR_FUN_004d2700;
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = (undefined1 *)0x0;
  }
  else {
    local_1 = (undefined1)((uint)param_1 >> 0x18);
    *(undefined4 *)(puVar1 + 4) = 0;
    *puVar1 = local_1;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
  }
  param_1[1] = puVar1;
  *(undefined1 *)(param_1 + 2) = 0;
  puVar2 = param_1 + 6;
  iVar3 = 4;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + -1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return param_1;
}

