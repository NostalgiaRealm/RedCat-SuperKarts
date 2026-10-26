/*
 * FUN_0040a120 at 0040a120
 * undefined1 __register FUN_0040a120(int param_1, int * param_2, double * param_3)
 * Address ranges: 0040a120-0040a2fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_0040a120(int param_1,int *param_2,double *param_3)

{
  char cVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  ushort local_1c;
  ushort local_1a;
  ushort local_18;
  ushort local_16;
  char local_14 [4];
  
  iVar5 = -1;
  cVar1 = FUN_00409be8(param_1,param_2,DAT_0047d508);
  if ((cVar1 == '\0') && (cVar1 = FUN_00409be8(param_1,param_2,&DAT_0040a304), cVar1 == '\0')) {
    cVar1 = FUN_00409be8(param_1,param_2,DAT_0047d50c);
    if ((cVar1 != '\0') || (cVar1 = FUN_00409be8(param_1,param_2,&DAT_0040a310), cVar1 != '\0')) {
      iVar5 = 0xc;
    }
  }
  else {
    iVar5 = 0;
  }
  if (-1 < iVar5) {
    FUN_00409b30(param_1,param_2);
  }
  bVar2 = FUN_00409b54(param_1,param_2,&local_1c,local_14);
  if (!bVar2) {
    return 0;
  }
  local_1a = 0;
  uVar4 = FUN_00409c74(param_1,param_2,DAT_0047d504);
  if (((char)uVar4 != '\0') && (bVar2 = FUN_00409b54(param_1,param_2,&local_1a,local_14), !bVar2)) {
    return 0;
  }
  local_18 = 0;
  uVar4 = FUN_00409c74(param_1,param_2,DAT_0047d504);
  if (((char)uVar4 != '\0') && (bVar2 = FUN_00409b54(param_1,param_2,&local_18,local_14), !bVar2)) {
    return 0;
  }
  local_16 = 0;
  uVar4 = FUN_00409c74(param_1,param_2,DAT_0047d4f7);
  if (((char)uVar4 != '\0') && (bVar2 = FUN_00409b54(param_1,param_2,&local_16,local_14), !bVar2)) {
    return 0;
  }
  if (iVar5 < 0) {
    cVar1 = FUN_00409be8(param_1,param_2,DAT_0047d508);
    if ((cVar1 == '\0') && (cVar1 = FUN_00409be8(param_1,param_2,&DAT_0040a304), cVar1 == '\0')) {
      cVar1 = FUN_00409be8(param_1,param_2,DAT_0047d50c);
      if ((cVar1 != '\0') || (cVar1 = FUN_00409be8(param_1,param_2,&DAT_0040a310), cVar1 != '\0')) {
        iVar5 = 0xc;
      }
    }
    else {
      iVar5 = 0;
    }
  }
  if (-1 < iVar5) {
    if (local_1c == 0) {
      return 0;
    }
    if (0xc < local_1c) {
      return 0;
    }
    if (local_1c == 0xc) {
      local_1c = 0;
    }
    local_1c = local_1c + (short)iVar5;
  }
  FUN_00409b30(param_1,param_2);
  uVar3 = FUN_00408be4(local_1c,local_1a,local_18,param_3,local_16);
  return uVar3;
}

