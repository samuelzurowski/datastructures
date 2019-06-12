points = []
depth = 1
def s2g(p):
    return (p[0] - width // 2, -(p[1] - height // 2))

def g2s(p):
    return (p[0] + width // 2, -p[1] + height // 2) 

def scale(p, factor):
    return (p[0]*factor, p[1]*factor)

def translate(p, vec):
    return(p[0] + vec[0], p[1] + vec[1])

def serpinski(p, depth=1):
    if depth <= 0:
        return
    
    line(p[0][0], p[0][1], p[1][0], p[1][1])
    line(p[1][0], p[1][1], p[2][0], p[2][1])
    line(p[2][0], p[2][1], p[0][0], p[0][1])
    
    #get midpoints
    a = ((p[0][0] + p[1][0]) / 2, (p[0][1] + p[1][1]) / 2)
    b = ((p[1][0] + p[2][0]) / 2, (p[0][1] + p[1][1]) / 2)
    c = ((p[0][0] + p[2][0]) / 2, p[0][1])

    #call on smaller triangles
    serpinski((p[0], a, c), depth-1)
    serpinski((a, p[1], b), depth-1)
    serpinski((c, b, p[2]), depth-1)

def setup():
    size(1200, 800)
    smooth(16)
    global points
    points.append(g2s(translate(scale((0, 0), 800), (-400, -350))))
    points.append(g2s(translate(scale((0.5, sin(radians(60))), 800), (-400, -350))))
    points.append(g2s(translate(scale((1, 0), 800), (-400, -350))))

def keyPressed():
    global depth
    if key == CODED:
        if keyCode == UP:
            depth += 1
        elif keyCode == DOWN:
            depth -= 1                 
                                          
def draw(): 
    background(255)
    stroke(0)
    global points
    global depth
    serpinski(points, depth)