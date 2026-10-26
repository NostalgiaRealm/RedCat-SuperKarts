/*
 * FUN_00457780 at 00457780
 * undefined FUN_00457780(void)
 * Address ranges: 00457780-00457aa9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00457780(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  FUN_004afce0(s___Search_existing_004f23c4);
  iVar2 = FUN_004576b0(param_2);
  if (iVar2 == -1) {
    FUN_004afce0(s___Searching_free_004f23d8);
    iVar2 = FUN_00457670();
    if (iVar2 < -1) {
      return 0;
    }
    piVar4 = (int *)(param_1 + iVar2 * 0x10);
    *(undefined1 *)(piVar4 + 3) = 1;
    FUN_004afce0(s___attach_assignment_004f23ec);
    cVar1 = FUN_00417e90(param_2);
    iVar2 = DAT_0053be28;
    if (cVar1 == '\0') {
      iVar2 = (&DAT_005081bc)[param_2 * 0x1c];
    }
    *piVar4 = iVar2;
    FUN_004afce0(s___creating_mesh_004f2404);
    iVar2 = FUN_0048fc70(0,0,0,0,0,0,0,0,0,0,0,0);
    piVar4[1] = iVar2;
    FUN_004afce0(s___Calculating_chunk_position_004f2418);
    FUN_004932e0(piVar4[1]);
    piVar4[2] = *(int *)(piVar4[1] * 0xd0 + 0xc + DAT_0067ee20);
    *(undefined4 *)(piVar4[1] * 0xd0 + 0x44 + DAT_0067ee20) = 0;
    iVar2 = *(int *)(*piVar4 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + DAT_006a5c38;
    iVar3 = DAT_006a5c38 + piVar4[2] * 0xa9;
    *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(iVar2 + 0x50);
    *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(iVar2 + 0x54);
    *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(iVar2 + 0x58);
    iVar2 = DAT_006a5c38 + piVar4[2] * 0xa9;
    *(undefined4 *)(iVar2 + 0x74) = 0;
    *(undefined4 *)(iVar2 + 0x78) = 0;
    *(undefined4 *)(iVar2 + 0x7c) = 0;
    *(undefined4 *)(piVar4[1] * 0xd0 + 0x24 + DAT_0067ee20) =
         *(undefined4 *)(*piVar4 * 0xd0 + 0x24 + DAT_0067ee20);
    *(undefined4 *)(piVar4[1] * 0xd0 + 0x44 + DAT_0067ee20) = 1;
    *(undefined4 *)(piVar4[1] * 0xd0 + 0x1c + DAT_0067ee20) =
         *(undefined4 *)(*piVar4 * 0xd0 + 0x1c + DAT_0067ee20);
    FUN_004a09e0();
    iVar2 = FUN_004a6200(s_bubble_004f2438);
    *(undefined4 *)(DAT_006a5c38 + piVar4[2] * 0xa9 + 0x99) =
         *(undefined4 *)(**(int **)(DAT_006a5f78 + iVar2 * 9 + 4) * 0x10 + DAT_006a5f30);
    iVar2 = FUN_004a6200(s_bubble_004f2440);
    *(undefined4 *)(DAT_006a5c38 + piVar4[2] * 0xa9 + 0x95) =
         *(undefined4 *)(**(int **)(DAT_006a5f78 + iVar2 * 9 + 4) * 0x10 + 4 + DAT_006a5f30);
    *(undefined4 *)(DAT_006a5c38 + piVar4[2] * 0xa9 + 0xa5) = 2;
  }
  return 1;
}

