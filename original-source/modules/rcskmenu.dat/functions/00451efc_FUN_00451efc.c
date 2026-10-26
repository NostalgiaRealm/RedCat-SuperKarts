/*
 * FUN_00451efc at 00451efc
 * uint __register FUN_00451efc(int param_1, uint param_2, int param_3)
 * Address ranges: 00451efc-00452020
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00451efc(int param_1,uint param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  
  FUN_00451dc0(param_1,param_2,param_3);
  uVar3 = 0;
  if ((((-1 < (int)param_2) && ((int)param_2 < *(int *)(param_1 + 0x8c))) && (-1 < param_3)) &&
     (param_3 < *(int *)(param_1 + 0x40))) {
    iVar2 = *(int *)(param_1 + 0x3c);
    if (iVar2 < 0x11) {
      if (iVar2 == 0x10) {
        uVar3 = (uint)*(ushort *)
                       (param_3 * *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x80) + param_2 * 2)
        ;
      }
      else if (iVar2 == 1) {
        uVar3 = ((uint)*(byte *)(param_3 * *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x80) +
                                (param_2 >> 3)) & *(uint *)(&DAT_0047bc08 + (param_2 & 7) * 4)) >>
                ((byte)*(undefined4 *)(&DAT_0047bc30 + (param_2 & 7) * 4) & 0x1f);
      }
      else if (iVar2 == 4) {
        uVar3 = ((uint)*(byte *)(param_3 * *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x80) +
                                (param_2 >> 1)) & *(uint *)(&DAT_0047bc28 + (param_2 & 1) * 4)) >>
                ((byte)*(undefined4 *)(&DAT_0047bc50 + (param_2 & 1) * 4) & 0x1f);
      }
      else if (iVar2 == 8) {
        uVar3 = (uint)*(byte *)(param_3 * *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x80) +
                               param_2);
      }
    }
    else if (iVar2 == 0x18) {
      puVar1 = (undefined1 *)
               (param_3 * *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x80) + param_2 * 3);
      uVar3 = (uint)CONCAT12(*puVar1,CONCAT11(puVar1[1],puVar1[2]));
    }
    else if (iVar2 == 0x20) {
      uVar3 = *(uint *)(param_3 * *(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x80) + param_2 * 4)
      ;
    }
  }
  return uVar3;
}

