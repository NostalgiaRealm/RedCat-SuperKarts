/*
 * FUN_00446e84 at 00446e84
 * bool __register FUN_00446e84(int * param_1, int param_2, int param_3, int param_4)
 * Address ranges: 00446e84-00446ec9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00446e84(int *param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  HIMAGELIST himlTrack;
  
  bVar1 = FUN_00433874((int)param_1);
  if (bVar1) {
    param_1[0x1c] = param_2;
    param_1[0x1a] = param_3;
    param_1[0x1b] = param_4;
    himlTrack = (HIMAGELIST)FUN_004339b0(param_1);
    ImageList_BeginDrag(himlTrack,param_2,param_3,param_4);
    *(undefined1 *)((int)param_1 + 0x62) = 1;
  }
  return bVar1;
}

