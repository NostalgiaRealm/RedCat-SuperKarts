/*
 * FUN_00474760 at 00474760
 * undefined FUN_00474760(void)
 * Address ranges: 00474760-00474844
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00474760(int param_1,int param_2)

{
  void *pvVar1;
  undefined1 *puVar2;
  LPCSTR lpFileName;
  DWORD DVar3;
  LPCSTR lpAppName;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004d0952;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_004afce0(s___Allocating_memory_004f786c);
  pvVar1 = operator_new(0x1000);
  *(void **)(param_1 + 0x28) = pvVar1;
  if (pvVar1 != (void *)0x0) {
    local_8 = 0xffffffff;
    puVar2 = *(undefined1 **)(param_2 + 4);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_004d2404;
    }
    FUN_004afce0(s___Loading_section_key_names_for___004f7884,puVar2);
    lpFileName = *(LPCSTR *)(param_1 + 0xc);
    if (lpFileName == (LPCSTR)0x0) {
      lpFileName = "";
    }
    lpAppName = *(LPCSTR *)(param_2 + 4);
    if (lpAppName == (LPCSTR)0x0) {
      lpAppName = "";
    }
    DVar3 = GetPrivateProfileStringA
                      (lpAppName,(LPCSTR)0x0,&DAT_00544dd8,*(LPSTR *)(param_1 + 0x28),0x1000,
                       lpFileName);
    if (DVar3 != 0) {
      FUN_004afce0(s___Loaded_section_succesfully_004f78c4);
      ExceptionList = local_10;
      return 1;
    }
    FUN_004afce0(s___failed_loading_section_004f78a8);
  }
  ExceptionList = local_10;
  return 0;
}

