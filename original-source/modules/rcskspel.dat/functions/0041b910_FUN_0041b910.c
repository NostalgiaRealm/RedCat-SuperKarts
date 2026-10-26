/*
 * FUN_0041b910 at 0041b910
 * undefined FUN_0041b910(void)
 * Address ranges: 0041b910-0041baed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b910(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  float10 fVar6;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  iVar1 = param_1;
  FUN_0041c4b0(param_1);
  FUN_0041cae0(param_1);
  param_1 = 0;
  if (0 < DAT_00508610) {
    pcVar4 = &DAT_00508214;
    do {
      cVar2 = FUN_00417e90(param_1);
      iVar3 = DAT_0053be28;
      if (cVar2 == '\0') {
        iVar3 = *(int *)(pcVar4 + -0x58);
      }
      if (iVar3 == iVar1) {
        cVar2 = DAT_0053bec4;
        if ((param_1 < DAT_00508610) && (0x508213 < (int)pcVar4)) {
          cVar2 = *pcVar4;
        }
        if ((cVar2 != '\0') ||
           (*(int *)(*(int *)(iVar1 * 0xd0 + 0x24 + DAT_0067ee20) * 0x50 + 4 + DAT_00680ae0) == 0x44
           )) {
          iVar5 = iVar1 * 0xd0;
          local_10 = 0;
          iVar3 = DAT_006a5c38 + *(int *)(iVar5 + 0xc + DAT_0067ee20) * 0xa9;
          FUN_00495fe0(*(undefined4 *)(iVar3 + 0x50),*(undefined4 *)(iVar3 + 0x54),
                       *(undefined4 *)(iVar3 + 0x58),&local_10,&local_8,&local_c);
          iVar3 = *(int *)(iVar5 + 0xc + DAT_0067ee20);
          local_4 = *(float *)(DAT_006a5c38 + iVar3 + 0x54 + iVar3 * 0xa8);
          iVar3 = DAT_006a5c38 + iVar3 + iVar3 * 0xa8;
          fVar6 = (float10)FUN_00496290(*(undefined4 *)(iVar3 + 0x50),*(undefined4 *)(iVar3 + 0x54),
                                        *(undefined4 *)(iVar3 + 0x58),local_8,local_c);
          if (((float10)local_4 - fVar6 < (float10)2.5) &&
             (4.0 < ABS(*(float *)(iVar5 + 0xa4 + DAT_0067ee20)))) {
            FUN_0041cb80(iVar1);
          }
        }
        cVar2 = DAT_0053bec5;
        if ((param_1 < DAT_00508610) && (0x508213 < (int)pcVar4)) {
          cVar2 = pcVar4[1];
        }
        if (cVar2 != '\0') {
          FUN_0041cba0(iVar1);
        }
      }
      param_1 = param_1 + 1;
      pcVar4 = pcVar4 + 0x70;
    } while (param_1 < DAT_00508610);
  }
  return;
}

