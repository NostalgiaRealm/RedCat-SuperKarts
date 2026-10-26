/*
 * FUN_004bf930 at 004bf930
 * undefined FUN_004bf930(void)
 * Address ranges: 004bf930-004bfa17
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_004bf930(undefined1 *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  
  piVar1 = param_4;
  uVar5 = param_2 * param_3;
  if (uVar5 == 0) {
    param_3 = 0;
  }
  else {
    puVar4 = param_1;
    param_1 = (undefined1 *)uVar5;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((*(ushort *)(piVar1 + 3) & 0x10c) == 0) || (uVar2 = piVar1[1], uVar2 == 0)) {
        if (param_1 < param_4) {
          iVar3 = FUN_004c4a82(piVar1);
          if (iVar3 == -1) goto LAB_004bfa0c;
          *puVar4 = (char)iVar3;
          param_4 = (int *)piVar1[6];
          puVar4 = puVar4 + 1;
          param_1 = (undefined1 *)((int)param_1 - 1);
        }
        else {
          uVar2 = (uint)param_1;
          if (param_4 != (int *)0x0) {
            uVar2 = (int)param_1 - (uint)param_1 % (uint)param_4;
          }
          iVar3 = FUN_004c4b5b(piVar1[4],puVar4,uVar2);
          if (iVar3 == 0) {
            piVar1[3] = piVar1[3] | 0x10;
LAB_004bfa0c:
            return (uVar5 - (int)param_1) / param_2;
          }
          if (iVar3 == -1) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_004bfa0c;
          }
          param_1 = (undefined1 *)((int)param_1 - iVar3);
          puVar4 = puVar4 + iVar3;
        }
      }
      else {
        uVar6 = (uint)param_1;
        if (uVar2 <= param_1) {
          uVar6 = uVar2;
        }
        FUN_004c0e10(puVar4,*piVar1,uVar6);
        param_1 = (undefined1 *)((int)param_1 - uVar6);
        piVar1[1] = piVar1[1] - uVar6;
        *piVar1 = *piVar1 + uVar6;
        puVar4 = puVar4 + uVar6;
      }
    } while (param_1 != (undefined1 *)0x0);
  }
  return param_3;
}

