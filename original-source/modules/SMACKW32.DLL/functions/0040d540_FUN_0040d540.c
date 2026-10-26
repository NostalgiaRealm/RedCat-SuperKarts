/*
 * FUN_0040d540 at 0040d540
 * undefined8 __fastcall FUN_0040d540(undefined4 param_1, undefined4 param_2, int param_3, uint * param_4)
 * Address ranges: 0040d540-0040d650
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_0040d540(undefined4 param_1,undefined4 param_2,int param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  short *psVar5;
  short *psVar6;
  
  if (*(char *)(param_3 + 0x20) == '\0') {
    psVar5 = *(short **)(param_3 + 0x34);
    if (*(char *)(param_3 + 0x21) == '\0') {
      if (*(char *)(param_3 + 0x22) == '\0') {
        psVar5 = (short *)(param_3 + 0x38);
        *(undefined1 *)(param_3 + 0x22) = 1;
      }
      uVar4 = *(uint *)(param_3 + 0x2c);
      uVar3 = *(uint *)(param_3 + 0x30);
      if (uVar3 < *(uint *)(param_3 + 0x28)) {
        if ((char)*psVar5 == '\0') {
          while ((char)*psVar5 == '\0') {
            psVar5 = (short *)((int)psVar5 + 1);
            for (uVar4 = uVar4 + 0x40; *(uint *)(param_3 + 0x24) <= uVar4;
                uVar4 = uVar4 - *(int *)(param_3 + 0x24)) {
              uVar3 = uVar3 + 4;
              if (*(uint *)(param_3 + 0x28) <= uVar3) goto LAB_0040d642;
            }
          }
          *(uint *)(param_3 + 0x30) = uVar3;
        }
        *param_4 = uVar4;
        param_4[1] = uVar3;
        param_4[3] = 4;
        param_4[2] = 0;
LAB_0040d5be:
        do {
          psVar6 = psVar5;
          uVar4 = uVar4 + 0x40;
          if (*(uint *)(param_3 + 0x24) <= uVar4) {
            iVar1 = uVar4 - *(int *)(param_3 + 0x24);
            *(int *)(param_3 + 0x2c) = iVar1;
            if (iVar1 != 0) {
              *(undefined1 *)(param_3 + 0x21) = 1;
            }
            param_4[2] = param_4[2] - (iVar1 + -0x40);
            *(int *)(param_3 + 0x30) = *(int *)(param_3 + 0x30) + 4;
            goto LAB_0040d5f3;
          }
          psVar5 = (short *)((int)psVar6 + 1);
          param_4[2] = param_4[2] + 0x40;
        } while (*(char *)psVar5 != '\0');
        *(uint *)(param_3 + 0x2c) = uVar4;
LAB_0040d5f3:
        uVar2 = 1;
        *(char **)(param_3 + 0x34) = (char *)((int)psVar6 + 1);
        goto LAB_0040d64a;
      }
    }
    else if (*(uint *)(param_3 + 0x30) < *(uint *)(param_3 + 0x28)) {
      param_4[1] = *(uint *)(param_3 + 0x30);
      *param_4 = 0;
      uVar4 = *(uint *)(param_3 + 0x2c);
      if (uVar4 < *(uint *)(param_3 + 0x24)) {
        *(undefined1 *)(param_3 + 0x21) = 0;
        param_4[2] = uVar4;
        if (*psVar5 != 0) goto LAB_0040d5be;
      }
      else {
        uVar3 = *(uint *)(param_3 + 0x24);
        param_4[2] = uVar3;
        *(uint *)(param_3 + 0x2c) = uVar4 - uVar3;
        *(int *)(param_3 + 0x30) = *(int *)(param_3 + 0x30) + 4;
      }
      param_4[3] = 4;
      uVar2 = 1;
      goto LAB_0040d64a;
    }
LAB_0040d642:
    *(char *)(param_3 + 0x20) = '\x01';
  }
  uVar2 = 0;
LAB_0040d64a:
  return CONCAT44(param_2,uVar2);
}

