/*
 * FUN_0040172c at 0040172c
 * undefined __register FUN_0040172c(uint param_1, int param_2, undefined4 * param_3)
 * Address ranges: 0040172c-004017bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040172c(uint param_1,int param_2,undefined4 *param_3)

{
  LPVOID pvVar1;
  LPVOID pvVar2;
  LPVOID lpAddress;
  LPVOID pvVar3;
  undefined4 *puVar4;
  LPVOID pvVar5;
  
  pvVar3 = (LPVOID)(param_1 & 0xfffff000);
  pvVar2 = (LPVOID)(param_1 + param_2 + 0xfff & 0xfffff000);
  *param_3 = pvVar3;
  param_3[1] = (int)pvVar2 - (int)pvVar3;
  puVar4 = DAT_0047d458;
  while( true ) {
    if ((undefined4 **)puVar4 == &DAT_0047d458) {
      return;
    }
    pvVar1 = (LPVOID)puVar4[2];
    lpAddress = pvVar1;
    if (pvVar1 < pvVar3) {
      lpAddress = pvVar3;
    }
    pvVar5 = (LPVOID)(puVar4[3] + (int)pvVar1);
    if (pvVar2 < (LPVOID)(puVar4[3] + (int)pvVar1)) {
      pvVar5 = pvVar2;
    }
    if ((lpAddress < pvVar5) &&
       (pvVar1 = VirtualAlloc(lpAddress,(int)pvVar5 - (int)lpAddress,0x1000,4),
       pvVar1 == (LPVOID)0x0)) break;
    puVar4 = (undefined4 *)*puVar4;
  }
  *param_3 = 0;
  return;
}

