/*
 * FUN_0040a550 at 0040a550
 * undefined FUN_0040a550(void)
 * Address ranges: 0040a550-0040a68e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a550(int param_1)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  int iVar4;
  float10 fVar5;
  
  piVar1 = &DAT_00503ef0 + param_1 * 0x47;
  iVar4 = FUN_00493a40(*(undefined4 *)(*piVar1 * 0xd0 + 0x1c + DAT_0067ee20),
                       *(undefined4 *)(DAT_0053be28 * 0xd0 + 0x1c + DAT_0067ee20));
  if (0x1e < iVar4) {
    *(undefined4 *)(*piVar1 * 0xd0 + 0x44 + DAT_0067ee20) = 0;
    FUN_00402850(param_1);
    return;
  }
  FUN_00413330(*piVar1);
  FUN_00412fd0(*piVar1);
  FUN_004130e0(*piVar1);
  fVar3 = *(float *)(*piVar1 * 0xd0 + 0xa4 + DAT_0067ee20);
  pfVar2 = (float *)(*piVar1 * 0xd0 + 0xa4 + DAT_0067ee20);
  fVar5 = (float10)FUN_0048f4e0();
  *pfVar2 = (float)((float10)*pfVar2 - fVar5 * (float10)(fVar3 * 3.0));
  fVar3 = *(float *)(*piVar1 * 0xd0 + 0x9c + DAT_0067ee20);
  pfVar2 = (float *)(*piVar1 * 0xd0 + 0x9c + DAT_0067ee20);
  fVar5 = (float10)FUN_0048f4e0();
  *pfVar2 = (float)((float10)*pfVar2 - fVar5 * (float10)(fVar3 * 3.0));
  fVar3 = *(float *)(*piVar1 * 0xd0 + 0xac + DAT_0067ee20);
  pfVar2 = (float *)(*piVar1 * 0xd0 + 0xac + DAT_0067ee20);
  fVar5 = (float10)FUN_0048f4e0();
  *pfVar2 = (float)((float10)*pfVar2 - fVar5 * (float10)(fVar3 * 3.0));
  return;
}

