/*
 * FUN_004406bc at 004406bc
 * undefined __register FUN_004406bc(int * param_1, uint * param_2, undefined4 param_3)
 * Address ranges: 004406bc-004407d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004406bc(int *param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  
  if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
    if ((*param_2 < 0x100) || (0x108 < *param_2)) {
      uVar1 = *param_2;
      if ((uVar1 < 0x200) || (0x20a < uVar1)) {
        if (uVar1 == 0xb00b) {
          FUN_0043f24c((int)param_1,0xb00b,param_2[1],param_2[2]);
        }
      }
      else {
        if (((*(byte *)(param_1 + 0x10) & 0x80) == 0) &&
           (((uVar1 == 0x203 || (uVar1 == 0x206)) || (uVar1 == 0x209)))) {
          *param_2 = *param_2 - 2;
        }
        uVar1 = *param_2;
        if (uVar1 == 0x200) {
          FUN_00432d10(*(int *)PTR_DAT_0047c86c,param_1,(int)param_2);
        }
        else {
          if (uVar1 != 0x201) {
            if (uVar1 == 0x202) {
              *(ushort *)(param_1 + 0x11) = *(ushort *)(param_1 + 0x11) & 0xfffe;
              goto LAB_004407c7;
            }
            if (uVar1 != 0x203) goto LAB_004407c7;
          }
          if (*(char *)((int)param_1 + 0x4d) == '\x01') {
            FUN_00403088(param_1,param_2,param_3);
            return;
          }
          *(ushort *)(param_1 + 0x11) = *(ushort *)(param_1 + 0x11) | 1;
        }
      }
      goto LAB_004407c7;
    }
    piVar3 = FUN_004298bc(param_1);
    if (piVar3 == (int *)0x0) goto LAB_004407c7;
    cVar2 = (**(code **)(*piVar3 + 0xdc))(piVar3,param_1,param_2);
  }
  else {
    piVar3 = FUN_004298bc(param_1);
    if ((piVar3 == (int *)0x0) || (piVar3[0x8e] == 0)) goto LAB_004407c7;
    cVar2 = (**(code **)(*(int *)piVar3[0x8e] + 0x24))((int *)piVar3[0x8e],param_1,param_2);
  }
  if (cVar2 != '\0') {
    return;
  }
LAB_004407c7:
  (**(code **)(*param_1 + -0x14))(param_1,param_2);
  return;
}

