/*
 * FUN_0048adc0 at 0048adc0
 * undefined FUN_0048adc0(void)
 * Address ranges: 0048adc0-0048aeff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0048ade0) */
/* WARNING: Removing unreachable block (ram,0x0048adf7) */
/* WARNING: Removing unreachable block (ram,0x0048ae04) */
/* WARNING: Removing unreachable block (ram,0x0048ae06) */
/* WARNING: Removing unreachable block (ram,0x0048ae11) */
/* WARNING: Removing unreachable block (ram,0x0048aed7) */

void __fastcall FUN_0048adc0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(iVar1 + 8);
  iVar2 = *(int *)(iVar1 + 4);
  for (iVar4 = iVar2; iVar4 != iVar3; iVar4 = iVar4 + 0x120) {
    FUN_0048aca0();
  }
  *(int *)(iVar1 + 8) = iVar2;
  return;
}

