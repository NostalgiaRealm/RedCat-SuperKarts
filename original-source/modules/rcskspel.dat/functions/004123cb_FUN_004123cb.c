/*
 * FUN_004123cb at 004123cb
 * undefined FUN_004123cb(void)
 * Address ranges: 004123cb-0041255c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004123cb(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *unaff_EDI;
  float10 fVar5;
  undefined4 in_stack_00000014;
  float fStack00000018;
  
  uVar2 = FUN_0040c8f0();
  uVar3 = FUN_0040c900();
  iVar4 = FUN_0040c970();
  fStack00000018 = 1.0;
  if (iVar4 != 0) {
    fStack00000018 = -1.0;
  }
  FUN_0040c990();
  FUN_00456aa0(uVar2,uVar3);
  FUN_0040c980();
  FUN_0040c9a0();
  fVar5 = (float10)FUN_00456aa0(uVar2,uVar3);
  puVar1 = (undefined4 *)(*unaff_EDI * 0xd0 + 0x9c + DAT_0067ee20);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  *(float *)(*unaff_EDI * 0xd0 + 0xac + DAT_0067ee20) =
       (float)(((float10)6.5 / fVar5) * (float10)fStack00000018);
  iVar4 = FUN_0040c970();
  if (iVar4 == 0) {
    FUN_0040c990();
  }
  else {
    FUN_00417e90(in_stack_00000014);
    FUN_0040c990();
  }
  iVar4 = __ftol();
  if (0 < iVar4) {
    FUN_00412330();
    return 0;
  }
  return 1;
}

