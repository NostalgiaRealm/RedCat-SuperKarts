/*
 * FUN_00404e5c at 00404e5c
 * undefined4 * __register FUN_00404e5c(undefined4 * param_1, int param_2)
 * Address ranges: 00404e5c-00404e95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_00404e5c(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  VARIANTARG *pVVar4;
  
  pVVar4 = (VARIANTARG *)*param_1;
  if (pVVar4 != (VARIANTARG *)0x0) {
    *param_1 = 0;
    LOCK();
    piVar1 = (int *)((int)&pVVar4[-1].n1 + 8);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      puVar2 = *(undefined4 **)(param_2 + 6 + (uint)*(byte *)(param_2 + 1));
      if ((puVar2 != (undefined4 *)0x0) && (iVar3 = *(int *)((int)&pVVar4[-1].n1 + 0xc), iVar3 != 0)
         ) {
        pVVar4 = FUN_004043f8(pVVar4,(char *)*puVar2,iVar3);
      }
      FUN_0040272c((int)((int)&pVVar4[-1].n1 + 8));
    }
  }
  return param_1;
}

