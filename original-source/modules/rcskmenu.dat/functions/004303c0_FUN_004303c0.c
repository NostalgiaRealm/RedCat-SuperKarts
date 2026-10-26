/*
 * FUN_004303c0 at 004303c0
 * undefined __register FUN_004303c0(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 004303c0-00430526;0043052e-0043056a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004303c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  byte *lpSubKey;
  LSTATUS LVar4;
  undefined4 *in_FS_OFFSET;
  DWORD ulOptions;
  REGSAM samDesired;
  HKEY *phkResult;
  undefined4 uStack_274;
  undefined1 *puStack_270;
  undefined1 *puStack_26c;
  int local_264;
  HKL local_260;
  undefined1 local_25c;
  byte local_258 [64];
  BYTE local_218 [256];
  HKL local_118 [64];
  HKL *local_18;
  int local_14;
  HKEY local_10;
  DWORD local_c;
  int local_8;
  
  puStack_26c = &stack0xfffffffc;
  local_264 = 0;
  puStack_270 = &LAB_0043056b;
  uStack_274 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_274;
  local_8 = param_1;
  if (*(int *)(param_1 + 0x28) == 0) {
    uVar2 = FUN_00402e7c((int *)&PTR_FUN_0040e2e8,'\x01',param_3);
    *(undefined4 *)(local_8 + 0x28) = uVar2;
    FUN_00403b50((int *)(local_8 + 0x2c));
    iVar3 = GetKeyboardLayoutList(0x40,local_118);
    if (-1 < iVar3 + -1) {
      local_18 = local_118;
      local_14 = iVar3;
      do {
        uVar2 = FUN_00449cac();
        if ((char)uVar2 != '\0') {
          phkResult = &local_10;
          samDesired = 0x20019;
          ulOptions = 0;
          local_260 = *local_18;
          local_25c = 0;
          lpSubKey = FUN_004089f4(local_258,
                                  (byte *)
                                  "System\\CurrentControlSet\\Control\\Keyboard Layouts\\%.8x",
                                  &local_260,0);
          LVar4 = RegOpenKeyExA((HKEY)0x80000002,(LPCSTR)lpSubKey,ulOptions,samDesired,phkResult);
          if (LVar4 == 0) {
            uVar2 = *in_FS_OFFSET;
            *in_FS_OFFSET = &stack0xfffffd80;
            local_c = 0x100;
            LVar4 = RegQueryValueExA(local_10,"layout text",(LPDWORD)0x0,(LPDWORD)0x0,local_218,
                                     &local_c);
            if (LVar4 == 0) {
              FUN_00403d80(&local_264,(char *)local_218,0x100);
              (**(code **)(**(int **)(local_8 + 0x28) + 0x38))
                        (*(int **)(local_8 + 0x28),local_264,*local_18);
              if (*local_18 == *(HKL *)(local_8 + 0x30)) {
                FUN_00403d80((int *)(local_8 + 0x2c),(char *)local_218,0x100);
              }
            }
            *in_FS_OFFSET = uVar2;
            RegCloseKey(local_10);
            return;
          }
        }
        local_18 = local_18 + 1;
        local_14 = local_14 + -1;
      } while (local_14 != 0);
    }
    piVar1 = *(int **)(local_8 + 0x28);
    *(undefined1 *)((int)piVar1 + 0x19) = 0;
    FUN_0041180c(piVar1,'\x01');
  }
  *in_FS_OFFSET = uStack_274;
  puStack_26c = &LAB_00430572;
  puStack_270 = (undefined1 *)0x43056a;
  FUN_00403b50(&local_264);
  return;
}

