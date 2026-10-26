/*
 * FUN_00453780 at 00453780
 * undefined FUN_00453780(void)
 * Address ranges: 00453780-004537ea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00453780(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  float10 fVar5;
  
  iVar2 = FUN_0044fff0();
  fVar5 = (float10)FUN_0048f4e0();
  iVar3 = FUN_004504f0();
  *(float *)(iVar2 + 4) = (float)iVar3 * (float)fVar5 + *(float *)(iVar2 + 4);
  uVar1 = *(undefined4 *)
           (DAT_006a5cd0 +
           ((int)(DAT_004fc8f0 + (DAT_004fc8f0 >> 0x1f & 7U)) >> 3 & DAT_004fc8f8) * 4);
  puVar4 = (undefined4 *)FUN_0044fff0();
  *puVar4 = uVar1;
  return;
}

