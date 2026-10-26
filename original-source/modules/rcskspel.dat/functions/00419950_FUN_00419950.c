/*
 * FUN_00419950 at 00419950
 * undefined FUN_00419950(void)
 * Address ranges: 00419950-00419b73
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00419950(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0x28;
  iVar3 = 0;
  FUN_00419790();
  iVar2 = FUN_004b3830();
  while (iVar2 == 0) {
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      FUN_004b1850(0,0,iVar4,&DAT_004e1bf8);
      iVar4 = iVar4 + -0x14;
      iVar3 = iVar3 + -1;
      if (iVar4 < 0x28) {
        iVar4 = 0x8c;
        iVar3 = 5;
      }
      FUN_004b1850(0,0,iVar4,&DAT_004e1bfc);
      FUN_00419230(0x26);
    }
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      FUN_004b1850(0,0,iVar4,&DAT_004e1c00);
      iVar4 = iVar4 + 0x14;
      iVar3 = iVar3 + 1;
      if (0x8c < iVar4) {
        iVar4 = 0x28;
        iVar3 = 0;
      }
      FUN_004b1850(0,0,iVar4,&DAT_004e1c04);
      FUN_00419230(0x28);
    }
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      iVar2 = iVar3 + DAT_0053be2c * 0x2b + DAT_0053bf00 * 6;
      fVar1 = *(float *)(&DAT_00505b9c + iVar2 * 4);
      *(float *)(&DAT_00505b9c + iVar2 * 4) = fVar1 - 0.1;
      if (fVar1 - 0.1 < 0.0) {
        *(undefined4 *)(&DAT_00505b9c + iVar2 * 4) = 0;
      }
      FUN_004b1850(0,0x14,(iVar3 * 5 + 10) * 4,s___Gear__d___f_004e1c08,iVar3 + 1,
                   (double)*(float *)(&DAT_00505b9c + iVar2 * 4));
      FUN_00419230(0x25);
    }
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      iVar2 = iVar3 + DAT_0053be2c * 0x2b + DAT_0053bf00 * 6;
      fVar1 = *(float *)(&DAT_00505b9c + iVar2 * 4);
      *(float *)(&DAT_00505b9c + iVar2 * 4) = fVar1 + 0.1;
      FUN_004b1850(0,0x14,(iVar3 * 5 + 10) * 4,s___Gear__d___f_004e1c18,iVar3 + 1,
                   (double)(fVar1 + 0.1));
      FUN_00419230(0x27);
    }
    iVar2 = FUN_004b3830();
    if (iVar2 != 0) {
      *(undefined4 *)(&DAT_00505b9c + (iVar3 + DAT_0053be2c * 0x2b + DAT_0053bf00 * 6) * 4) = 0;
      FUN_004b1850(0,0x14,(iVar3 * 5 + 10) * 4,s___Gear__d___f_004e1c28,iVar3 + 1,0);
      FUN_00419230(0x52);
    }
    iVar2 = FUN_004b3830();
  }
  FUN_00419230();
  return;
}

