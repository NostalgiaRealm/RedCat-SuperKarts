/*
 * FUN_004017c0 at 004017c0
 * undefined __register FUN_004017c0(int param_1, int param_2, undefined4 * param_3)
 * Address ranges: 004017c0-0040183c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004017c0(int param_1,int param_2,undefined4 *param_3)

{
  LPVOID pvVar1;
  BOOL BVar2;
  LPVOID lpAddress;
  LPVOID pvVar3;
  LPVOID pvVar4;
  undefined4 *puVar5;
  LPVOID pvVar6;
  
  pvVar4 = (LPVOID)(param_1 + 0xfffU & 0xfffff000);
  pvVar3 = (LPVOID)(param_1 + param_2 & 0xfffff000);
  *param_3 = pvVar4;
  param_3[1] = (int)pvVar3 - (int)pvVar4;
  for (puVar5 = DAT_0047d458; (undefined4 **)puVar5 != &DAT_0047d458; puVar5 = (undefined4 *)*puVar5
      ) {
    pvVar1 = (LPVOID)puVar5[2];
    lpAddress = pvVar1;
    if (pvVar1 < pvVar4) {
      lpAddress = pvVar4;
    }
    pvVar6 = (LPVOID)(puVar5[3] + (int)pvVar1);
    if (pvVar3 < (LPVOID)(puVar5[3] + (int)pvVar1)) {
      pvVar6 = pvVar3;
    }
    if (lpAddress < pvVar6) {
      BVar2 = VirtualFree(lpAddress,(int)pvVar6 - (int)lpAddress,0x4000);
      if (BVar2 == 0) {
        DAT_0047d434 = 2;
      }
    }
  }
  return;
}

