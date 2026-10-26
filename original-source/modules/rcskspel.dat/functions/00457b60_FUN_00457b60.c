/*
 * FUN_00457b60 at 00457b60
 * undefined FUN_00457b60(void)
 * Address ranges: 00457b60-00457d01
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_00457b60(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  if (DAT_00508610 != -1 && -1 < DAT_00508610 + 1) {
    piVar3 = (int *)(param_1 + 8);
    do {
      if ((char)piVar3[1] != '\0') {
        FUN_004afce0(s__s__d____Handling__d_004f2498,s_D__work_rcsk_Code_game_rcr_bubbl_004f2468,
                     0xf1,iVar4);
        FUN_004afce0(s___Updating_position_004f24b0);
        iVar1 = *(int *)(piVar3[-2] * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + DAT_006a5c38;
        iVar2 = DAT_006a5c38 + *piVar3 * 0xa9;
        *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(iVar1 + 0x50);
        *(undefined4 *)(iVar2 + 0x54) = *(undefined4 *)(iVar1 + 0x54);
        *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(iVar1 + 0x58);
        FUN_004afce0(s___Updating_rotation_004f24c8);
        iVar1 = DAT_006a5c38 + *piVar3 * 0xa9;
        *(undefined4 *)(iVar1 + 0x74) = 0;
        *(undefined4 *)(iVar1 + 0x78) = 0;
        *(undefined4 *)(iVar1 + 0x7c) = 0;
        FUN_004afce0(s___Updating_waypoint_004f24e0);
        *(undefined4 *)(piVar3[-1] * 0xd0 + 0x24 + DAT_0067ee20) =
             *(undefined4 *)(piVar3[-2] * 0xd0 + 0x24 + DAT_0067ee20);
        FUN_004afce0(s___Updatiung_chunk_004f24f8);
        *(undefined4 *)(piVar3[-1] * 0xd0 + 0x1c + DAT_0067ee20) =
             *(undefined4 *)(piVar3[-2] * 0xd0 + 0x1c + DAT_0067ee20);
        FUN_004afce0(s___Updating_the_matrix_004f250c);
        FUN_004a09e0();
        FUN_004afce0(s___Updating_camera_view_004f2524);
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 4;
    } while (iVar4 < DAT_00508610 + 1);
    return 0x7b;
  }
  return 0x7b;
}

