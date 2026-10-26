/*
 * FUN_00454510 at 00454510
 * undefined __register FUN_00454510(int param_1, int param_2)
 * Address ranges: 00454510-00454649
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454510(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *unaff_EBX;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  int *in_FS_OFFSET;
  int local_2c;
  undefined1 *local_28;
  undefined4 *local_24;
  char *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = (char *)0x4;
  do {
    local_14 = local_14 + -1;
  } while (local_14 != (char *)0x0);
  LOCK();
  UNLOCK();
  local_c = 0;
  local_24 = (undefined4 *)0x454537;
  local_8 = param_2;
  FUN_00403f84(param_2);
  local_24 = (undefined4 *)0x45453f;
  FUN_00403f84(local_c);
  local_28 = &LAB_0045464a;
  local_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_2c;
  local_24 = (undefined4 *)&stack0xfffffffc;
  FUN_00454504(param_1);
  iVar1 = FUN_00403dd0(local_c);
  if (iVar1 == 0) {
    FUN_00403be8((int *)&local_14,0x454660);
  }
  else {
    FUN_00403be8((int *)&local_14,local_c);
  }
  FUN_00403b50(&local_10);
  iVar1 = FUN_00403dd0(local_8);
  if (0 < iVar1) {
    iVar3 = 1;
    do {
      FUN_00403cf8((int *)&stack0xffffffe8,
                   CONCAT31((int3)((uint)local_8 >> 8),*(undefined1 *)(local_8 + -1 + iVar3)));
      iVar2 = FUN_004040bc(unaff_EBX,local_14);
      if (iVar2 < 1) {
        FUN_00403cf8((int *)&local_24,
                     CONCAT31((int3)((uint)local_8 >> 8),*(undefined1 *)(local_8 + -1 + iVar3)));
        FUN_00403dd8(&local_10,local_24);
      }
      else {
        FUN_00407e94(local_10,(int *)&stack0xffffffe0);
        FUN_00407ec8(unaff_EDI,(int *)&stack0xffffffe4);
        FUN_00454668(param_1,unaff_ESI);
        FUN_00403b50(&local_10);
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  iVar1 = FUN_00403dd0(local_10);
  if (0 < iVar1) {
    FUN_00407e94(local_10,&local_2c);
    FUN_00407ec8(local_2c,(int *)&local_28);
    FUN_00454668(param_1,(int)local_28);
    FUN_00403b50(&local_10);
  }
  *in_FS_OFFSET = local_2c;
  local_24 = (undefined4 *)&LAB_00454651;
  local_28 = (undefined1 *)0x454649;
  FUN_00403b74(&local_2c,10);
  return;
}

