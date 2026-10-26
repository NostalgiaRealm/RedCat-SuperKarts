/*
 * FUN_004090a8 at 004090a8
 * undefined __register FUN_004090a8(int param_1, int * param_2, undefined4 param_3, int param_4)
 * Address ranges: 004090a8-004091f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004090a8(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  LPCSTR lpFormat;
  LCID Locale;
  uint uVar1;
  undefined4 *in_FS_OFFSET;
  DWORD dwFlags;
  SYSTEMTIME *lpDate;
  CHAR *lpDateStr;
  int iVar2;
  int *piVar3;
  undefined4 uStack_130;
  undefined1 *puStack_12c;
  undefined1 *puStack_128;
  undefined4 local_11c;
  CHAR local_118 [256];
  SYSTEMTIME local_18;
  undefined *local_8;
  
  puStack_128 = &stack0xfffffffc;
  local_11c = 0;
  local_8 = (undefined *)0x0;
  puStack_12c = &LAB_004091fa;
  uStack_130 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_130;
  FUN_00403b50(param_2);
  local_18.wYear = *(WORD *)(param_4 + -0xe);
  local_18.wMonth = *(WORD *)(param_4 + -0x10);
  local_18.wDay = *(WORD *)(param_4 + -0x12);
  FUN_00403be8((int *)&local_8,0x409210);
  iVar2 = 0x100;
  lpDateStr = local_118;
  lpFormat = FUN_00403f94(local_8);
  lpDate = &local_18;
  dwFlags = 4;
  Locale = GetThreadLocale();
  iVar2 = GetDateFormatA(Locale,dwFlags,lpDate,lpFormat,lpDateStr,iVar2);
  if (iVar2 != 0) {
    FUN_00403d80(param_2,local_118,0x100);
    if (param_1 == 1) {
      if (DAT_0047d5b4 == 4) {
        if (DAT_0047d5b6 == 1) {
          iVar2 = FUN_00403dd0(*param_2);
          iVar2 = FUN_0040b5ac(*param_2,iVar2);
          if (iVar2 == 4) {
            iVar2 = FUN_0040b698(*param_2,3);
            FUN_00403d08(&local_11c,local_118 + iVar2 + -1);
            uVar1 = FUN_0040b6fc(local_11c,2);
            FUN_00403c38(param_2,(undefined4 *)(local_118 + iVar2 + -1),uVar1);
          }
        }
      }
      else if (DAT_0047d5b4 == 0x11) {
        piVar3 = param_2;
        uVar1 = FUN_0040b6fc(*param_2,1);
        FUN_00403fd8(*param_2,1,uVar1,piVar3);
      }
    }
  }
  *in_FS_OFFSET = uStack_130;
  puStack_128 = &LAB_00409201;
  puStack_12c = (undefined1 *)0x4091f1;
  FUN_00403b50(&local_11c);
  puStack_12c = (undefined1 *)0x4091f9;
  FUN_00403b50((int *)&local_8);
  return;
}

