clear;

LK25 = fscanfMat("./pomiary/pomiar_LK_25.0%.txt");
LK50 = fscanfMat("./pomiary/pomiar_LK_50.0%.txt");
LK75 = fscanfMat("./pomiary/pomiar_LK_75.0%.txt");
LK100 = fscanfMat("./pomiary/pomiar_LK_100.0%.txt");
LS25 = fscanfMat("./pomiary/pomiar_LS_25.0%.txt");
LS50 = fscanfMat("./pomiary/pomiar_LS_50.0%.txt");
LS75 = fscanfMat("./pomiary/pomiar_LS_75.0%.txt");
LS100 = fscanfMat("./pomiary/pomiar_LS_100.0%.txt");
MS25 = fscanfMat("./pomiary/pomiar_MS_25.0%.txt");
MS50 = fscanfMat("./pomiary/pomiar_MS_50.0%.txt");
MS75 = fscanfMat("./pomiary/pomiar_MS_75.0%.txt");
MS100 = fscanfMat("./pomiary/pomiar_MS_100.0%.txt");

pomiary1 = [LK25, LK50, LS25, LS50, MS25, MS50];
pomiary2 = [LK75, LK100, LS75, LS100, MS75, MS100];

rozmiary = [10, 50, 100, 500, 1000];

for i=1:6
    subplot(3, 2, i);
    plot(rozmiary, pomiary1(:, 2*i-1, :), 'b.');
    plot(rozmiary, pomiary1(:, 2*i  , :), 'g.');
    xlabel('ilosc wierzcholkow');
    ylabel('czas [ms]');
end

figure(1);
for i=1:6
    subplot(3, 2, i);
    plot(rozmiary, pomiary2(:, 2*i-1, :), 'b.');
    plot(rozmiary, pomiary2(:, 2*i  , :), 'g.');
    xlabel('ilosc wierzcholkow');
    ylabel('czas [ms]');
end
