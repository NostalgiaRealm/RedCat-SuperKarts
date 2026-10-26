/*
 * FUN_00448580 at 00448580
 * undefined FUN_00448580(void)
 * Address ranges: 00448580-0044877b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00448580(undefined1 *param_1)

{
  char cVar1;
  int iVar2;
  float *pfVar3;
  uint3 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  float10 fVar9;
  undefined4 *puStack_44;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined1 auStack_c [12];
  
  FUN_0040b4f0(0);
  uVar5 = 0xffffffff;
  pcVar8 = (char *)&DAT_004efd30;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5 - 1;
  cVar1 = FUN_0040b600(uVar5,1);
  if (cVar1 != '\0') {
    puVar7 = &DAT_004efd30;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puStack_44 = *puVar7;
      puVar7 = puVar7 + 1;
      puStack_44 = puStack_44 + 1;
    }
    for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puStack_44 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puStack_44 = (undefined4 *)((int)puStack_44 + 1);
    }
    FUN_0040b5e0(uVar5);
  }
  FUN_0044d4d0();
  FUN_0044d4b0();
  iVar2 = FUN_0044f9d0();
  if (*(int *)(param_1 + 8) < *(int *)(param_1 + 4) + -2) {
    pfVar3 = (float *)FUN_00445120(&fStack_18,*(undefined4 *)(param_1 + 0x18));
    fStack_24 = *pfVar3;
    fStack_20 = pfVar3[1];
    fStack_1c = pfVar3[2];
    pfVar3 = (float *)FUN_00445120(auStack_c,*(undefined4 *)(param_1 + 0x18),
                                   *(undefined4 *)(param_1 + 4),*(int *)(param_1 + 8) + 1,
                                   *(undefined4 *)(param_1 + 0xc),param_1[0x1d]);
    fStack_18 = *pfVar3;
    fStack_14 = pfVar3[1];
    fStack_10 = pfVar3[2];
  }
  iVar2 = iVar2 * 0xd0;
  *(int *)(iVar2 + 0x1c + DAT_0067ee20) = DAT_0053be40;
  if (*(int *)(param_1 + 8) < *(int *)(param_1 + 4) + -2) {
    fVar9 = (float10)fpatan((float10)fStack_10 - (float10)fStack_1c,
                            (float10)fStack_18 - (float10)fStack_24);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    *(float *)(DAT_006a5c38 + *(int *)(iVar2 + 0xc + DAT_0067ee20) * 0xa9 + 0x78) =
         (float)(((fVar9 - (float10)3.1415927 * (float10)0.5) * (float10)_DAT_004fc8f4) /
                (float10)6.2831855);
    iVar2 = DAT_006a5c38 + *(int *)(iVar2 + 0xc + DAT_0067ee20) * 0xa9;
    *(float *)(iVar2 + 0x50) = fStack_24;
    *(float *)(iVar2 + 0x54) = fStack_20;
    *(float *)(iVar2 + 0x58) = fStack_1c;
    FUN_004a09e0();
  }
  iVar2 = *(int *)(&DAT_0053f664 + *(int *)(param_1 + 0x18) * 0x340);
  uVar4 = (uint3)((uint)iVar2 >> 8);
  if ((iVar2 != 0) && (iVar2 == DAT_0053be40)) {
    *param_1 = 0;
    return CONCAT31(uVar4,1);
  }
  return (uint)uVar4 << 8;
}

