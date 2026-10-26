/*
 * FUN_00409214 at 00409214
 * undefined __register FUN_00409214(int param_1, int * param_2, undefined4 param_3, int param_4)
 * Address ranges: 00409214-004092f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409214(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  LPCSTR lpFormat;
  LCID Locale;
  undefined4 *in_FS_OFFSET;
  DWORD dwFlags;
  SYSTEMTIME *lpDate;
  CHAR *lpDateStr;
  int iVar1;
  int *piVar2;
  undefined4 uStack_12c;
  undefined1 *puStack_128;
  undefined1 *puStack_124;
  CHAR local_118 [256];
  SYSTEMTIME local_18;
  undefined *local_8;
  
  puStack_124 = &stack0xfffffffc;
  local_8 = (undefined *)0x0;
  puStack_128 = &LAB_004092f2;
  uStack_12c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_12c;
  FUN_00403b50(param_2);
  local_18.wYear = *(WORD *)(param_4 + -0xe);
  local_18.wMonth = *(WORD *)(param_4 + -0x10);
  local_18.wDay = *(WORD *)(param_4 + -0x12);
  if (param_1 < 3) {
    FUN_00403be8((int *)&local_8,0x409308);
  }
  else {
    FUN_00403be8((int *)&local_8,0x409314);
  }
  iVar1 = 0x100;
  lpDateStr = local_118;
  lpFormat = FUN_00403f94(local_8);
  lpDate = &local_18;
  dwFlags = 4;
  Locale = GetThreadLocale();
  iVar1 = GetDateFormatA(Locale,dwFlags,lpDate,lpFormat,lpDateStr,iVar1);
  if (iVar1 != 0) {
    FUN_00403d80(param_2,local_118,0x100);
    if ((param_1 == 1) && (*(char *)*param_2 == '0')) {
      piVar2 = param_2;
      iVar1 = FUN_00403dd0(*param_2);
      FUN_00403fd8(*param_2,2,iVar1 - 1,piVar2);
    }
  }
  *in_FS_OFFSET = uStack_12c;
  puStack_124 = &LAB_004092f9;
  puStack_128 = (undefined1 *)0x4092f1;
  FUN_00403b50((int *)&local_8);
  return;
}

