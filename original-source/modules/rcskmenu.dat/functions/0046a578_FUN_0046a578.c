/*
 * FUN_0046a578 at 0046a578
 * undefined FUN_0046a578(void)
 * Address ranges: 0046a578-0046a59d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_0046a578(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)FUN_00402714(0x10);
    puVar3 = puVar1;
    for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + (uint)bVar4 * -2 + 1;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
  }
  return puVar1;
}

