/*
 * FUN_00401570 at 00401570
 * undefined FUN_00401570(void)
 * Address ranges: 00401570-004016d4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401570(int param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  float fStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  iVar6 = param_1 * 0x11c;
  if (*(float *)(&DAT_00503f04 + iVar6) <= 1.0) {
    piVar1 = (int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20);
    fStack_c = *(float *)(*(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + DAT_006a5c38 +
                         0x50);
    uStack_8 = *(undefined4 *)(*piVar1 * 0xa9 + DAT_006a5c38 + 0x54);
    fStack_4 = *(float *)(*piVar1 * 0xa9 + DAT_006a5c38 + 0x58);
    iVar5 = *(int *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xc + DAT_0067ee20);
    fVar2 = *(float *)(DAT_006a5c38 + iVar5 + 0x50 + iVar5 * 0xa8) - fStack_c;
    fVar3 = *(float *)(DAT_006a5c38 + iVar5 + 0x58 + iVar5 * 0xa8) - fStack_4;
    if (((fVar2 * fVar2 + fVar3 * fVar3 < 10000.0) &&
        (iVar5 = FUN_00401320((&DAT_00503ef0)[param_1 * 0x47],&fStack_c), 0x5dc < iVar5)) &&
       (iVar5 < 0x9c4)) {
      cVar4 = FUN_00417e90(param_1);
      iVar5 = DAT_0053be60;
      if (cVar4 == '\0') {
        iVar5 = (&DAT_005081b8)[param_1 * 0x1c];
      }
      if (iVar5 == 0) {
        *(int *)(&DAT_00503ef8 + iVar6) = DAT_0053be28;
        return 1;
      }
    }
  }
  else {
    *(undefined4 *)(&DAT_00503f04 + iVar6) = 0;
  }
  return 0;
}

