/*
 * FUN_00412560 at 00412560
 * undefined FUN_00412560(void)
 * Address ranges: 00412560-004126a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00412560(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  
  if (0.0 <= (float)param_2[0x26]) {
    cVar1 = FUN_00417e90(param_1);
    uVar3 = DAT_0053be28;
    if (cVar1 == '\0') {
      uVar3 = (&DAT_005081bc)[param_1 * 0x1c];
    }
    iVar2 = FUN_00417050(uVar3);
    if (iVar2 < 4) {
      iVar2 = *param_2;
      fVar4 = (float10)FUN_0048f4e0();
      param_2[0x26] = (int)(float)((float10)(float)param_2[0x26] - fVar4);
      uVar3 = FUN_0040c900();
      FUN_00456aa0(2,uVar3);
      *(undefined4 *)(iVar2 * 0xd0 + 0x9c + DAT_0067ee20) = 0;
      *(undefined4 *)(iVar2 * 0xd0 + 0xa4 + DAT_0067ee20) = 0;
      FUN_00413330(*param_2);
      FUN_004130e0(*param_2);
      FUN_00412fd0(*param_2);
      return 1;
    }
  }
  FUN_00413330(*param_2);
  FUN_004130e0(*param_2);
  FUN_00412fd0(*param_2);
  if ((char)param_2[0x3f] != '\0') {
    iVar2 = FUN_004906b0(2);
    if (0.0 < *(float *)(DAT_006a5c38 + iVar2 * 0xa9 + 0x60)) {
      return 1;
    }
    FUN_00457730(param_1);
    FUN_00457ab0(param_1);
    *(undefined1 *)(param_2 + 0x3f) = 0;
  }
  return 0;
}

